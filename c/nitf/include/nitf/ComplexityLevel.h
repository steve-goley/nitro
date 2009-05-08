/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 *
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program;
 * If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __NITF_COMPLEXITY_LEVEL_H__
#define __NITF_COMPLEXITY_LEVEL_H__

#include "nitf/Record.h"
#include "nitf/System.h"

NITF_CXX_GUARD

/*!
 *  This file makes it easy to compute and recompute the CLEVEL.
 *  It only works on 2.1 files, not on legacy 2.0.
 *
 */

typedef enum _NITF_CLEVEL
{
    NITF_CLEVEL_CHECK_FAILED = 0,
    NITF_CLEVEL_03,
    NITF_CLEVEL_05,
    NITF_CLEVEL_06,
    NITF_CLEVEL_07,
    NITF_CLEVEL_09,
    NITF_CLEVEL_UNKNOWN
} NITF_CLEVEL;

/*!
 *  This function attempts to measure the CLEVEL of a NITF 2.1 record.
 *  The record should be populated with all of the meta-data, so that it
 *  can be measured.
 *
 *  This function is 'class-static' in the sense that we provide no
 *  ComplexityLevel class publicly.  Internally, its represented as a set
 *  of function pointers that act on the nitf_Record.
 *
 *  This API call is new for 2.5.  As of 2.5, the Writer will 
 *  also use this function internally to checking if a Record's
 *  complexity level has not yet been set, and if not, it will 
 *  attempt to auto-calculate it.
 *
 *  \param record The input record (its clevel is not modified for this op)
 *
 *  \param error [output] Contains an error if one exists (in which case 
 *  the return value will be NITF_CLEVEL_CHECK_FAILED
 *
 *  \return A clevel if determined, NITF_CLEVEL_CHECK_FAILED on error
 *
 */
NITFAPI(NITF_CLEVEL) nitf_ComplexityLevel_measure(nitf_Record* record,
                                                  nitf_Error* error);

NITF_CXX_ENDGUARD

#endif
