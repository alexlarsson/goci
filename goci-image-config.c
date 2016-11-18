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

#include "goci-image-config.h"

G_DEFINE_TYPE (GociImageConfig, goci_image_config, GOCI_TYPE_JSON);

static void
goci_image_config_finalize (GObject *object)
{
  GociImageConfig *self = (GociImageConfig *) object;

  g_free (self->user);
  g_free (self->working_dir);
  g_strfreev (self->env);
  g_strfreev (self->cmd);
  g_strfreev (self->entrypoint);
  g_strfreev (self->exposed_ports);
  g_strfreev (self->volumes);
  if (self->labels)
    g_hash_table_destroy (self->labels);

  G_OBJECT_CLASS (goci_image_config_parent_class)->finalize (object);
}

static void
goci_image_config_class_init (GociImageConfigClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GociJsonClass *json_class = GOCI_JSON_CLASS (klass);
  static GociJsonProp props[] = {
    GOCI_JSON_STRING_PROP (GociImageConfig, user, "User"),
    GOCI_JSON_INT64_PROP (GociImageConfig, memory, "Memory"),
    GOCI_JSON_INT64_PROP (GociImageConfig, memory_swap, "MemorySwap"),
    GOCI_JSON_INT64_PROP (GociImageConfig, cpu_shares, "CpuShares"),
    GOCI_JSON_BOOLMAP_PROP (GociImageConfig, exposed_ports, "ExposedPorts"),
    GOCI_JSON_STRV_PROP (GociImageConfig, env, "Env"),
    GOCI_JSON_STRV_PROP (GociImageConfig, entrypoint, "Entrypoint"),
    GOCI_JSON_STRV_PROP (GociImageConfig, cmd, "Cmd"),
    GOCI_JSON_BOOLMAP_PROP (GociImageConfig, volumes, "Volumes"),
    GOCI_JSON_STRING_PROP (GociImageConfig, working_dir, "WorkingDir"),
    GOCI_JSON_STRMAP_PROP(GociImageConfig, labels, "Labels"),
    GOCI_JSON_LAST_PROP
  };

  object_class->finalize = goci_image_config_finalize;
  json_class->props = props;
}

static void
goci_image_config_init (GociImageConfig *self)
{
}
