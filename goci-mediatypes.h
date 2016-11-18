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

#ifndef __GOCI_MEDIATYPES_H__
#define __GOCI_MEDIATYPES_H__

#include <glib.h>

G_BEGIN_DECLS

#define GOCI_MEDIA_TYPE_DESCRIPTOR "application/vnd.oci.descriptor.v1+json"
#define GOCI_MEDIA_TYPE_IMAGE_MANIFEST "application/vnd.oci.image.manifest.v1+json"
#define GOCI_MEDIA_TYPE_IMAGE_MANIFESTLIST "application/vnd.oci.image.manifest.list.v1+json"
#define GOCI_MEDIA_TYPE_IMAGE_LAYER "application/vnd.oci.image.layer.v1.tar+gzip"
#define GOCI_MEDIA_TYPE_IMAGE_LAYER_NONDISTRIBUTABLE "application/vnd.oci.image.layer.nondistributable.v1.tar+gzip"
#define GOCI_MEDIA_TYPE_IMAGE_CONFIG "application/vnd.oci.image.config.v1+json"

G_END_DECLS

#endif /* __GOCI_MEDIATYPES_H__ */
