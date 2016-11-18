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

#include "goci-image-rootfs.h"

G_DEFINE_TYPE (GociImageRootfs, goci_image_rootfs, GOCI_TYPE_JSON);

static void
goci_image_rootfs_finalize (GObject *object)
{
  GociImageRootfs *self = (GociImageRootfs *) object;

  g_free (self->type);
  g_strfreev (self->diff_ids);

  G_OBJECT_CLASS (goci_image_rootfs_parent_class)->finalize (object);
}

static void
goci_image_rootfs_class_init (GociImageRootfsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_STRING_PROP (GociImageRootfs, type, "type"),
    GOCI_JSON_STRV_PROP (GociImageRootfs, diff_ids, "diff_ids"),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_image_rootfs_finalize;
  json_class->props = props;
}

static void
goci_image_rootfs_init (GociImageRootfs *self)
{
}
