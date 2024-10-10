/************************************************************************
 * Copyright(c) 2004-2018, THERMUS Project,        All rights reserved. *
 *                                                                      *
 * Author: The THERMUS Project (A Thermal Model Package for ROOT).      *
 * Contributors (UCT-IPHC) are mentioned in the code where appropriate. *
 *                                                                      *
 * Permission to use, copy, modify and distribute this software and its *
 * documentation strictly for non-commercial purposes is hereby granted *
 * without fee, provided that the above copyright notice appears in all *
 * copies and that both the copyright notice and this permission notice *
 * appear in the supporting documentation. The authors make no claims   *
 * about the suitability of this software for any purpose. It is        *
 * provided "as is" without express or implied warranty.                *
 ************************************************************************/

// Author: Spencer Wheaton 7 January 2005       //
// Adapted for GSL: Yves Schutz October 2017    //

#include "FncsConstrain.h"

#include "TTMDensObj.h"
#include "TThermalModelBSQ.h"

//__________________________________________________________________________
Int_t BSQfuncSBDens(const gsl_vector* x, void* p, gsl_vector* f)
{
    Int_t rv = 0;
    TTMThermalModelBSQ* model = ((PARAMETERSS *)p)->p0;
    
    (model->GetParameterSet())->GetParameter(2)->SetValue(gsl_vector_get(x, 0));
    (model->GetParameterSet())->GetParameter(1)->SetValue(gsl_vector_get(x, 1));
    
    Int_t check = model->PrimPartDens();
    
    if (!check) {
        Double_t sb0 = ((PARAMETERSS *)p)->p1;
        if (sb0 != 0.)
            gsl_vector_set(f, 0, (model->GetStrange() - sb0) / sb0);
        else
            gsl_vector_set(f, 0, (model->GetStrange() - sb0) / (TMath::Abs(model->GetSplus()) + TMath::Abs(model->GetSminus())));
        
        TIter next(model->GetDensityTable());
        TTMDensObj *dens;
        Double_t nb = 0.;
        
        while((dens = (TTMDensObj *)next())){
            Int_t id = dens->GetID();
            TTMParticle *part = model->GetParticleSet()->GetParticle(id);
            Double_t partdens =  dens->GetPrimDensity();
            if(part->GetB() != 0.){
                nb += partdens;
            }
        }
        Double_t sb1 = ((PARAMETERSS *)p)->p2;
        gsl_vector_set(f, 1, (nb - sb1) / sb1);
    } else {
        cout << "Primary particles density problems!" << endl;
        rv = 1;
    }
    return rv;
}
