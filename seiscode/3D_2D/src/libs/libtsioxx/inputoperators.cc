/*! \file inputoperators.cc
 * \brief input operators for SFF TimeSeries traces and files for libdatrwxx
 *        streams (implementation).
 * 
 * ----------------------------------------------------------------------------
 * 
 * \author Thomas Forbriger
 * \since 18/07/2005
 * \date 30/01/2014
 * 
 * input operators for SFF TimeSeries traces and files for libdatrwxx streams
 * (implementation)
 * 
 * Copyright (c) 2005-2007, 2012, 2014 by Thomas Forbriger (BFO Schiltach) 
 *
 * ----
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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 * ----
 *
 * REVISIONS and CHANGES 
 *  - 30/01/2014   V1.0   Thomas Forbriger (thof):
 *                        copied from sffheaders.cc
 * 
 * ============================================================================
 */
#define TSIO_INPUTOPERATORS_CC_VERSION \
  "TF_INPUTOPERATORS_CC   2014/01/30"

#include <tsioxx/inputoperators.h>

namespace ts {

  namespace sff {

    datrw::idatstream& operator>>(datrw::idatstream& is, 
                                    FileHeader& fh)
    {
      ::sff::FREE free;
      ::sff::SRCE srce;
      fh=FileHeader();
      if (is.hasfree()) { is >> free; fh.free(free); } 
      if (is.hassrce()) { is >> srce; fh.srce(srce); } 
      return(is);
    }

    datrw::idatstream& operator>>(datrw::idatstream& is, 
                                    TraceHeader& th)
    {
      ::sff::FREE free;
      ::sff::INFO info;
      ::sff::WID2 wid2;
      th=TraceHeader();
      is >> wid2; th.wid2(wid2); 
      if (is.hasfree()) { is >> free; th.free(free); } 
      if (is.hasinfo()) { is >> info; th.info(info); } 
      return(is);
    }

  } // namespace sff
} // namespace ts

/* ----- END OF inputoperators.cc ----- */
