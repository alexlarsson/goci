/*
 * Copyright © 2016 Red Hat, Inc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *       Alexander Larsson <alexl@redhat.com>
 */

#include "config.h"

#include <string.h>

#include "goci-manifest-list.h"
#include "goci-mediatypes.h"
#include "goci-descriptor.h"

G_DEFINE_TYPE (GociManifestList, goci_manifest_list, GOCI_TYPE_VERSIONED);

static void
goci_manifest_list_finalize (GObject *object)
{
  GociManifestList *self = (GociManifestList *) object;

  g_list_free_full (self->manifests, g_object_unref);
  if (self->annotations)
    g_hash_table_destroy (self->annotations);

  G_OBJECT_CLASS (goci_manifest_list_parent_class)->finalize (object);
}


static void
goci_manifest_list_class_init (GociManifestListClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_OBJECTLIST_PROP(GociManifestList, manifests, "manifests", goci_manifest_descriptor_get_type),
    GOCI_JSON_STRMAP_PROP(GociManifestList, annotations, "annotations"),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_manifest_list_finalize;
  json_class->props = props;
}

static void
goci_manifest_list_init (GociManifestList *self)
{
}
