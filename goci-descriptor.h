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

#ifndef __GOCI_DESCRIPTOR_H__
#define __GOCI_DESCRIPTOR_H__

#include "goci-json.h"

G_BEGIN_DECLS

#define GOCI_TYPE_DESCRIPTOR goci_descriptor_get_type ()
G_DECLARE_FINAL_TYPE (GociDescriptor, goci_descriptor, GOCI, DESCRIPTOR, GociJson)

struct _GociDescriptor {
  GociJson parent;

  char *mediatype;
  char *digest;
  gint64 size;
  char **urls;
};

struct _GociDescriptorClass {
  GociJsonClass parent_class;
};

G_END_DECLS

#endif /* __GOCI_DESCRIPTOR_H__ */
