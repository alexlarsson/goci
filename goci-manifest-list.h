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

#ifndef __GOCI_MANIFEST_LIST_H__
#define __GOCI_MANIFEST_LIST_H__

#include "goci-versioned.h"
#include "goci-manifest-descriptor.h"

G_BEGIN_DECLS

#define GOCI_TYPE_MANIFEST_LIST goci_manifest_list_get_type ()
G_DECLARE_FINAL_TYPE (GociManifestList, goci_manifest_list, GOCI, MANIFEST_LIST, GociVersioned)

struct _GociManifestList
{
  GociVersioned parent;

  GList          *manifests;
  GHashTable     *annotations;
};

struct _GociManifestListClass
{
  GociVersionedClass parent_class;
};

G_END_DECLS

#endif /* __GOCI_MANIFEST_LIST_H__ */
