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
#include "goci-descriptor.h"

G_DEFINE_TYPE (GociDescriptor, goci_descriptor, GOCI_TYPE_JSON);

static void
goci_descriptor_finalize (GObject *object)
{
  GociDescriptor *self = GOCI_DESCRIPTOR (object);

  g_free (self->mediatype);
  g_free (self->digest);
  g_strfreev (self->urls);

  G_OBJECT_CLASS (goci_descriptor_parent_class)->finalize (object);
}


static void
goci_descriptor_class_init (GociDescriptorClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_STRING_PROP (GociDescriptor, mediatype, "mediaType"),
    GOCI_JSON_STRING_PROP (GociDescriptor, digest, "digest"),
    GOCI_JSON_INT64_PROP (GociDescriptor, size, "size"),
    GOCI_JSON_STRV_PROP (GociDescriptor, urls, "urls"),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_descriptor_finalize;
  json_class->props = props;
}

static void
goci_descriptor_init (GociDescriptor *self)
{
}
