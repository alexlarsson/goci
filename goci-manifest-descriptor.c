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

#include "goci-manifest-descriptor.h"

G_DEFINE_TYPE (GociManifestDescriptor, goci_manifest_descriptor, GOCI_TYPE_DESCRIPTOR);

static void
goci_manifest_descriptor_finalize (GObject *object)
{
  GociManifestDescriptor *self = (GociManifestDescriptor *) object;

  g_clear_object (&self->platform);

  G_OBJECT_CLASS (goci_manifest_descriptor_parent_class)->finalize (object);
}

static void
goci_manifest_descriptor_class_init (GociManifestDescriptorClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_OBJECT_PROP (GociManifestDescriptor, platform, "platform", goci_manifest_platform_get_type),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_manifest_descriptor_finalize;
  json_class->props = props;
}

static void
goci_manifest_descriptor_init (GociManifestDescriptor *self)
{
}
