/*
 * Copyright (C) 2015 Red Hat, Inc
 *
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *       Alexander Larsson <alexl@redhat.com>
 */

#include "config.h"
#include "string.h"

#include "goci-mediatypes.h"
#include "goci-versioned.h"
#include "goci-manifest.h"
#include "goci-manifest-list.h"

G_DEFINE_TYPE (GociVersioned, goci_versioned, GOCI_TYPE_JSON);

static void
goci_versioned_finalize (GObject *object)
{
  GociVersioned *self = GOCI_VERSIONED (object);

  g_free (self->mediatype);

  G_OBJECT_CLASS (goci_versioned_parent_class)->finalize (object);
}

static void
goci_versioned_class_init (GociVersionedClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_INT64_PROP (GociVersioned, version, "schemaVersion"),
    GOCI_JSON_STRING_PROP (GociVersioned, mediatype, "mediaType"),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_versioned_finalize;
  json_class->props = props;
}

static void
goci_versioned_init (GociVersioned *self)
{
}

GociVersioned *
goci_versioned_from_json (JsonNode *node, GError **error)
{
  JsonObject *object = json_node_get_object (node);
  const gchar *mediatype;

  mediatype = json_object_get_string_member (object, "mediaType");
  if (mediatype == NULL)
    {
      g_set_error (error, G_IO_ERROR, G_IO_ERROR_INVALID_ARGUMENT,
                   "Versioned object lacks mediatype");
      return NULL;
    }

  if (strcmp (mediatype, GOCI_MEDIA_TYPE_IMAGE_MANIFEST) == 0)
    return (GociVersioned *) goci_json_from_node (node, GOCI_TYPE_MANIFEST, error);

  if (strcmp (mediatype, GOCI_MEDIA_TYPE_IMAGE_MANIFESTLIST) == 0)
    return (GociVersioned *) goci_json_from_node (node, GOCI_TYPE_MANIFEST_LIST, error);
  g_set_error (error, G_IO_ERROR, G_IO_ERROR_INVALID_ARGUMENT,
               "Unsupported media type %s", mediatype);
  return NULL;
}
