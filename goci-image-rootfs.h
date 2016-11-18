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

#ifndef __GOCI_IMAGE_ROOTFS_H__
#define __GOCI_IMAGE_ROOTFS_H__

#include "goci-versioned.h"

G_BEGIN_DECLS

#define GOCI_TYPE_IMAGE_ROOTFS goci_image_rootfs_get_type ()
G_DECLARE_FINAL_TYPE (GociImageRootfs, goci_image_rootfs, GOCI, IMAGE_ROOTFS, GociJson)

struct _GociImageRootfs
{
  GociJson parent;

  char *type;
  char **diff_ids;
};

struct _GociImageRootfsClass
{
  GociJsonClass parent_class;
};

G_END_DECLS

#endif /* __GOCI_IMAGE_ROOTFS_H__ */
