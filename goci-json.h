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

#ifndef __GOCI_JSON_H__
#define __GOCI_JSON_H__

#include <json-glib/json-glib.h>

G_BEGIN_DECLS

#define GOCI_TYPE_JSON goci_json_get_type ()
G_DECLARE_DERIVABLE_TYPE (GociJson, goci_json, GOCI, JSON, GObject)

typedef enum {
  GOCI_JSON_PROP_TYPE_STRING,
  GOCI_JSON_PROP_TYPE_INT64,
  GOCI_JSON_PROP_TYPE_BOOL,
  GOCI_JSON_PROP_TYPE_STRV,
  GOCI_JSON_PROP_TYPE_OBJECT,
  GOCI_JSON_PROP_TYPE_OBJECTLIST,
  GOCI_JSON_PROP_TYPE_STRMAP,
  GOCI_JSON_PROP_TYPE_BOOLMAP,
} GociJsonPropType;

typedef struct {
  const char *name;
  gsize offset;
  GociJsonPropType type;
  gpointer type_data;
} GociJsonProp;

#define GOCI_JSON_STRING_PROP(_struct, _field, _name) { _name, G_STRUCT_OFFSET (_struct, _field), GOCI_JSON_PROP_TYPE_STRING }
#define GOCI_JSON_INT64_PROP(_struct, _field, _name) { _name, G_STRUCT_OFFSET (_struct, _field), GOCI_JSON_PROP_TYPE_INT64 }
#define GOCI_JSON_BOOL_PROP(_struct, _field, _name) { _name, G_STRUCT_OFFSET (_struct, _field), GOCI_JSON_PROP_TYPE_BOOL }
#define GOCI_JSON_STRV_PROP(_struct, _field, _name) { _name, G_STRUCT_OFFSET (_struct, _field), GOCI_JSON_PROP_TYPE_STRV }
#define GOCI_JSON_STRMAP_PROP(_struct, _field, _name) { _name, G_STRUCT_OFFSET (_struct, _field), GOCI_JSON_PROP_TYPE_STRMAP }
#define GOCI_JSON_BOOLMAP_PROP(_struct, _field, _name) { _name, G_STRUCT_OFFSET (_struct, _field), GOCI_JSON_PROP_TYPE_BOOLMAP }
#define GOCI_JSON_OBJECT_PROP(_struct, _field, _name, _type) { _name, G_STRUCT_OFFSET (_struct, _field), GOCI_JSON_PROP_TYPE_OBJECT, (gpointer)_type }
#define GOCI_JSON_OBJECTLIST_PROP(_struct, _field, _name, _type) { _name, G_STRUCT_OFFSET (_struct, _field), GOCI_JSON_PROP_TYPE_OBJECTLIST, (gpointer)_type }
#define GOCI_JSON_LAST_PROP { NULL }

struct _GociJsonClass {
  GObjectClass parent_class;

  GociJsonProp *props;
};

GociJson * goci_json_from_node (JsonNode *node, GType type, GError **error);
JsonNode *goci_json_to_node (GociJson *self);

G_END_DECLS

#endif /* __GOCI_JSON_H__ */
