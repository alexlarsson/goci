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

#ifndef __GOCI_IMAGE_CONFIG_H__
#define __GOCI_IMAGE_CONFIG_H__

#include "goci-json.h"

G_BEGIN_DECLS

#define GOCI_TYPE_IMAGE_CONFIG goci_image_config_get_type ()
G_DECLARE_FINAL_TYPE (GociImageConfig, goci_image_config, GOCI, IMAGE_CONFIG, GociJson)

struct _GociImageConfig
{
  GociJson parent;

  char *user;

  char *working_dir;
  gint64 memory;
  gint64 memory_swap;
  gint64 cpu_shares;
  char **env;
  char **cmd;
  char **entrypoint;
  char **exposed_ports;
  char **volumes;
  GHashTable *labels;
};

struct _GociImageConfigClass
{
  GociJsonClass parent_class;
};

G_END_DECLS

#endif /* __GOCI_IMAGE_CONFIG_H__ */
