/******************************************************************************/
/*                            This file is part of                            */
/*                       BEAVER, a MOOSE-based application                    */
/*       Multiphase Flow Poromechanics for Induced Seismicity Problems        */
/*                                                                            */
/*                  Copyright (C) 2022 by Antoine B. Jacquey                  */
/*                  Tufts University / Polytechnique Montreal                 */
/*                                                                            */
/*            Licensed under GNU Lesser General Public License v2.1           */
/*                       please see LICENSE for details                       */
/*                 or http://www.gnu.org/licenses/lgpl.html                   */
/******************************************************************************/

#pragma once

#include "Material.h"

class BVInelasticUpdateBase : public Material
{
public:
  static InputParameters validParams();
  BVInelasticUpdateBase(const InputParameters & parameters);
  void setQp(unsigned int qp);
  virtual void inelasticUpdate(ADRankTwoTensor & stress,
                               const RankFourTensor & Cijkl,
                               ADRankTwoTensor & strain_increment) = 0;
  void resetQpProperties() final {}
  void resetProperties() final {}

protected:
  const Real _abs_tol;
  const Real _rel_tol;
  unsigned int _max_its;
};