/*! \file firfilters.cc
 * \brief all we need to implement FIR filters (implementation)
 * 
 * ----------------------------------------------------------------------------
 * 
 * \author Thomas Forbriger
 * \date 21/11/2006
 * 
 * all we need to implement FIR filters (implementation)
 * 
 * Copyright (c) 2006 by Thomas Forbriger (BFO Schiltach) 
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
 *  - 21/11/2006   V1.0   Thomas Forbriger
 * 
 * ============================================================================
 */
#define TF_FIRFILTERS_CC_VERSION \
  "TF_FIRFILTERS_CC   V1.0   "

#include <tsxx/tsxx.h>
#include <tsxx/firfilters.h>

namespace ts {

  namespace fir {

    const double SeisCompMPc[]=
      {
         -2.54066472E-05, -6.09197377E-05, -8.40882202E-05, -8.40244538E-05,
         1.63391334E-04, 5.16510103E-04,  7.65687436E-04,  7.80274858E-04,
         -4.45842306E-04, -2.25522625E-03, -3.62849165E-03, -3.78991523E-03,
         3.44818312E-04, 6.77778524E-03, 1.20854378E-02, 1.30976140E-02,
         2.24578497E-03, -1.63416173E-02, -3.37996147E-02, -3.94811071E-02,
         -1.46564310E-02,  4.01543528E-02,  1.14328198E-01,  1.89809903E-01,
         2.33582660E-01
      };

    const FIR SeisCompMP={
      "MP",
      "multi-stop-band used for decimation only",
      50,
      25,
      true,
      4,
      1.,
      SeisCompMPc
    };

    /*----------------------------------------------------------------------*/

    const double SeisCompLPc[]=
      {
         3.23645679E-07,  6.27603639E-07, 5.75629996E-07, -1.00657667E-06,
         -6.27801819E-06 , -1.86042925E-05, -4.24696263E-05, -8.29456912E-05,
         -1.44627949E-04, -2.30086734E-04 , -3.38065990E-04, -4.61854768E-04,
         -5.88392838E-04, -6.98681862E-04, -7.69910286E-04 , -7.79347843E-04,
         -7.09572690E-04, -5.54065569E-04, -3.21793486E-04, -3.92671027E-05 ,
         2.51179503E-04,  4.97445289E-04,  6.47570472E-04, 6.61840895E-04,
         5.24436298E-04 , 2.51484307E-04, -1.07339962E-04, -4.75387409E-04,
         -7.63640680E-04, -8.91005444E-04 , -8.05950839E-04, -5.03994466E-04,
         -3.56691998E-05, 4.98732435E-04, 9.68361273E-04 ,  1.24199199E-03,
         1.22272572E-03, 8.78496851E-04,  2.59474473E-04, -5.04297786E-04 ,
         -1.22721668E-03, -1.71084259E-03, -1.79588736E-03, -1.41046755E-03,
         -6.00851606E-04 ,  4.66098572E-04,  1.53319922E-03,  2.31183949E-03,
         2.55692657E-03, 2.13922281E-03 , 1.09476235E-03, -3.65161395E-04,
         -1.89103966E-03, -3.07469396E-03, -3.55443242E-03 , -3.11977649E-03,
         -1.78673980E-03,  1.80607851E-04, 2.31448258E-03, 4.04895190E-03 ,
         4.86453622E-03,  4.43631876E-03, 2.74506560E-03,  1.16539268E-04,
         -2.82981922E-03 , -5.31874457E-03, -6.61512510E-03, -6.23058853E-03,
         -4.08509001E-03, -5.74231205E-04 ,  3.48643888E-03,  7.03835300E-03,
         9.04299877E-03, 8.76884627E-03, 6.02670246E-03 , 1.28392561E-03,
         -4.38675517E-03, -9.52839944E-03, -1.26505149E-02, -1.26299141E-02 ,
         -9.06068924E-03, -2.45481194E-03,  5.77654549E-03, 1.35813886E-02,
         1.87259223E-02 ,  1.93600226E-02,  1.45586589E-02, 4.70184255E-03,
         -8.41764453E-03, -2.18134336E-02 , -3.18325236E-02, -3.48961763E-02,
         -2.83033009E-02, -1.09193558E-02, 1.64119005E-02 ,  5.08435964E-02,
         8.79169851E-02,  1.22306898E-01, 1.48779303E-01, 1.63167998E-01
      };

    const FIR SeisCompLP={
      "LP",
      "single-stop-band low-pass",
      200,
      100,
      true,
      5,
      4.,
      SeisCompLPc
    };

    /*----------------------------------------------------------------------*/

    const double SeisCompVLPc[]=
      {
        -1.28828092E-09,  9.14503405E-09,  2.87476904E-08,  7.11241767E-08,
        1.51310061E-07 ,  2.91624161E-07,  5.23189498E-07,  8.87843213E-07,
        1.44005162E-06, 2.24865971E-06 ,  3.39826488E-06,  4.98999634E-06,
        7.14144197E-06,  9.98547874E-06, 1.36677381E-05 ,  1.83425054E-05,
        2.41668694E-05,  3.12930642E-05,  3.98589945E-05, 4.99771267E-05 ,
        6.17220211E-05,  7.51170082E-05,  9.01205857E-05,  1.06613370E-04,
        1.24386483E-04 ,  1.43132449E-04,  1.62439595E-04,  1.81791096E-04,
        2.00569513E-04, 2.18067856E-04 ,  2.33507438E-04,  2.46062962E-04,
        2.54894577E-04,  2.59186228E-04, 2.58189102E-04 ,  2.51268851E-04,
        2.37953820E-04,  2.17982247E-04,  1.91345360E-04, 1.58323091E-04 ,
        1.19509517E-04,  7.58249953E-05,  2.85122951E-05, -2.08851106E-05,
        -7.05638885E-05 , -1.18520940E-04, -1.62631870E-04, -2.00745591E-04,
        -2.30791746E-04, -2.50896090E-04 , -2.59498571E-04, -2.55466904E-04,
        -2.38199442E-04, -2.07709323E-04, -1.64683297E-04 , -1.10509143E-04,
        -4.72663596E-05,  2.23230290E-05,  9.49848763E-05, 1.67023521E-04 ,
        2.34488980E-04,  2.93374469E-04,  3.39835649E-04,  3.70420748E-04,
        3.82298807E-04 ,  3.73472488E-04,  3.42961138E-04,  2.90940603E-04,
        2.18827306E-04, 1.29296604E-04 ,  2.62285666E-05, -8.54221797E-05,
        -1.99831178E-04, -3.10577452E-04, -4.10974869E-04 , -4.94446256E-04,
        -5.54921105E-04, -5.87234622E-04, -5.87504298E-04, -5.53458347E-04 ,
        -4.84693009E-04, -3.82836529E-04, -2.51602934E-04, -9.67231389E-05,
        7.42515621E-05 ,  2.52271566E-04,  4.27226506E-04,  5.88479800E-04,
        7.25475081E-04, 8.28381569E-04 ,  8.88742855E-04,  9.00087353E-04,
        8.58461483E-04,  7.62846262E-04, 6.15422613E-04 ,  4.21659147E-04,
        1.90203253E-04, -6.74309048E-05, -3.37372737E-04, -6.04086031E-04 ,
        -8.51209566E-04, -1.06250588E-03, -1.22286635E-03, -1.31931377E-03,
        -1.34193967E-03 , -1.28471490E-03, -1.14611199E-03, -9.29490662E-04,
        -6.43205188E-04, -3.00409156E-04 ,  8.14499435E-05,  4.81434777E-04,
        8.76190140E-04,  1.24123308E-03, 1.55239471E-03 ,  1.78733305E-03,
        1.92702783E-03,  1.95716135E-03,  1.86929386E-03, 1.66174676E-03 ,
        1.34011928E-03,  9.17386088E-04,  4.13541769E-04, -1.45211466E-04,
        -7.27711361E-04 , -1.29946659E-03, -1.82459201E-03, -2.26794835E-03,
        -2.59736110E-03, -2.78579164E-03 , -2.81331502E-03, -2.66877771E-03,
        -2.35100835E-03, -1.86948047E-03, -1.24435790E-03 , -5.05877833E-04,
        3.06923466E-04,  1.14810548E-03,  1.96725572E-03, 2.71234126E-03 ,
        3.33282724E-03,  3.78288654E-03,  4.02450701E-03,  4.03029890E-03,
        3.78581485E-03 ,  3.29120969E-03,  2.56210216E-03,  1.62953662E-03,
        5.39001426E-04, -6.51497160E-04 , -1.87423802E-03, -3.05534713E-03,
        -4.11894545E-03, -4.99166501E-03, -5.60728460E-03 , -5.91120961E-03,
        -5.86451776E-03, -5.44730760E-03, -4.66110836E-03, -3.53014865E-03 ,
        -2.10134988E-03, -4.42970165E-04,  1.35810394E-03,  3.20033333E-03,
        4.97261155E-03 ,  6.56023062E-03,  7.85143300E-03,  8.74420720E-03,
        9.15295816E-03, 9.01466794E-03 ,  8.29416885E-03,  6.98819290E-03,
        5.12791099E-03,  2.77973572E-03, 4.42597047E-05 , -2.94670439E-03,
        -6.03491859E-03, -9.04218107E-03, -1.17781861E-02, -1.40494322E-02 ,
        -1.56687591E-02, -1.64650455E-02, -1.62925646E-02, -1.50395213E-02,
        -1.26352794E-02 , -9.05589386E-03, -4.32758638E-03,  1.47205416E-03,
        8.21529421E-03, 1.57279000E-02 ,  2.37950831E-02,  3.21695320E-02,
        4.05811667E-02,  4.87481765E-02, 5.63888475E-02 ,  6.32336214E-02,
        6.90367594E-02,  7.35871717E-02,  7.67176896E-02, 7.83125534E-02
      };

    const FIR SeisCompVLP={
      "VLP",
      "single-stop-band low-pass",
      400,
      200,
      true,
      10,
      4.,
      SeisCompVLPc
    };

    /*======================================================================*/

    const FIR* FIRfilters[]=
    {
      &SeisCompMP,
      &SeisCompLP,
      &SeisCompVLP,
      0x00
    };

    /*======================================================================*/

    std::ostream& operator<<(std::ostream& os, const FIR& fir)
    {
      os << "FIR filter " << fir.name << ":" << std::endl;
      os << "    " << fir.description << std::endl;
      os << "    number of coefficients: " << fir.points
        << ", delay: " << fir.delay 
        << ", decimation: " << fir.decimation_factor
        << ", gain: " << fir.gain << std::endl;
      os << "    the filter is ";
      if (!fir.symmetric) { os << "non-"; }
      os << "symmetric" << std::endl;
      return(os);
    }

    /*----------------------------------------------------------------------*/

    void help(std::ostream& os)
    {
      os << "The following FIR filters are available:" << std::endl;
      int i=0;
      while (FIRfilters[i] != 0)
      { os << *FIRfilters[i]; ++i; }
    }


  } // namespace fir

} // namespace ts

/* ----- END OF firfilters.cc ----- */