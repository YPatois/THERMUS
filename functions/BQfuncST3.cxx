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

// Author: Spencer Wheaton 14 July 2004         //
// Adapted for GSL: Yves Schutz September 2017  //

#include "FncsConstrain.h"

#include "TTMParameterSetBQ.h"
#include "TThermalModelBQ.h"

//__________________________________________________________________________
Int_t BQfuncST3(const gsl_vector* x, void* p, gsl_vector* f)
{
    Int_t rv = 0;
    TTMThermalModelBQ* model = ((PARAMETERS *)p)->p0;
    (model->GetParameterSet())->GetParameter(1)->SetValue(gsl_vector_get(x, 0));
    
    Int_t check = model->PrimPartDens();
    
    if (!check) {
        model->GenerateEntropyDens();
        Double_t st3 = ((PARAMETERS*)p)->p1;
        gsl_vector_set(f, 0, (model->GetEntropy() / pow(model->GetParameterSet()->GetT(), 3.) * pow(0.197,3.) -
                              st3) / st3);
    } else {
       cout << "Primary particles density problems!" << endl;
        rv = 1;
    }
    return rv;
}
