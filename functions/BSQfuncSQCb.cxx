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

// Author: Spencer Wheaton 26 April 2010        //
// Adapted for GSL: Yves Schutz October 2017    //

#include "FncsConstrain.h"

#include "TThermalModelBSQ.h"

//__________________________________________________________________________
Int_t BSQfuncSQCb(const gsl_vector* x, void* p, gsl_vector* f)
{
    Int_t rv = 0;
    TTMThermalModelBSQ* model = ((PARAMETERSS *)p)->p0;
    
    (model->GetParameterSet())->GetParameter(2)->SetValue(gsl_vector_get(x, 0));
    (model->GetParameterSet())->GetParameter(3)->SetValue(gsl_vector_get(x, 1));
    (model->GetParameterSet())->GetParameter(6)->SetValue(gsl_vector_get(x, 2));
    (model->GetParameterSet())->GetParameter(8)->SetValue(gsl_vector_get(x, 3));
    
    Int_t check = model->PrimPartDens();
    
    if (!check) {
        Double_t y0 = model->GetParameterSet()->GetSDens();
        Double_t y1 = model->GetParameterSet()->GetB2Q();
        Double_t y2 = model->GetParameterSet()->GetCDens();
        Double_t y3 = model->GetParameterSet()->GetbDens();
        
        
        if (y0 != 0.)
            gsl_vector_set(f, 0, (model->GetStrange() - y0) / y0);
        else
            gsl_vector_set(f, 0, (model->GetStrange() - y0) / (TMath::Abs(model->GetSplus()) + TMath::Abs(model->GetSminus())));
        
        gsl_vector_set(f, 1, (model->GetBaryon() / 2. / model->GetCharge() - y1) / y1);
        
        if (y2 != 0.)
            gsl_vector_set(f, 2, (model->GetCharm() - y2) / y2);
        else
            gsl_vector_set(f, 2, (model->GetCharm() - y2) / (TMath::Abs(model->GetCplus()) + TMath::Abs(model->GetCminus())));
        
        if (y3 != 0.)
            gsl_vector_set(f, 3, (model->GetBeauty() - y3) / y3);
        else
            gsl_vector_set(f, 3, (model->GetBeauty() - y3) / (TMath::Abs(model->Getbplus()) + TMath::Abs(model->Getbminus())));
    } else {
        cout << "Primary particles density problems!" << endl;
        rv = 1;
    }
    return rv;
}
