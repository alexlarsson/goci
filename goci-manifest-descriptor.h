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

#ifndef __GOCI_MANIFEST_DESCRIPTOR_H__
#define __GOCI_MANIFEST_DESCRIPTOR_H__

#include "goci-descriptor.h"
#include "goci-manifest-platform.h"

G_BEGIN_DECLS

#define GOCI_TYPE_MANIFEST_DESCRIPTOR goci_manifest_descriptor_get_type ()
G_DECLARE_FINAL_TYPE (GociManifestDescriptor, goci_manifest_descriptor, GOCI, MANIFEST_DESCRIPTOR, GociDescriptor)

struct _GociManifestDescriptor
{
  GociDescriptor parent;

  GociManifestPlatform *platform;
};

struct _GociManifestDescriptorClass
{
  GociDescriptorClass parent_class;
};

G_END_DECLS

#endif /* __GOCI_MANIFEST_H__ */
