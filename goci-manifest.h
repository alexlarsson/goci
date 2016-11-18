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

#ifndef __GOCI_MANIFEST_H__
#define __GOCI_MANIFEST_H__

#include "goci-versioned.h"
#include "goci-descriptor.h"

G_BEGIN_DECLS

#define GOCI_TYPE_MANIFEST goci_manifest_get_type ()
G_DECLARE_FINAL_TYPE (GociManifest, goci_manifest, GOCI, MANIFEST, GociVersioned)

GociManifest * goci_manifest_new (void);

struct _GociManifest
{
  GociVersioned parent;

  GociDescriptor *config;
  GList          *layers;
  GHashTable     *annotations;
};

struct _GociManifestClass
{
  GociVersionedClass parent_class;
};

G_END_DECLS

#endif /* __GOCI_MANIFEST_H__ */
