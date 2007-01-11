/*
 * Copyright (c) 2003, 2006 Matteo Frigo
 * Copyright (c) 2003, 2006 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */


#include "mpi-transpose.h"
#include "mpi-dft.h"

static const solvtab s =
{
     SOLVTAB(XM(transpose_pairwise_register)),
     SOLVTAB(XM(transpose_alltoall_register)),
     SOLVTAB(XM(transpose_radix2_register)),
     SOLVTAB(XM(dft_rank_geq2_register)),
     SOLVTAB(XM(dft_rank_geq2_transposed_register)),
     SOLVTAB(XM(dft_serial_register)),
     SOLVTAB(XM(dft_rank1_bigvec_register)),
     SOLVTAB(XM(dft_rank1_register)),
     SOLVTAB_END
};

void XM(conf_standard)(planner *p)
{
     X(solvtab_exec)(s, p);
}
