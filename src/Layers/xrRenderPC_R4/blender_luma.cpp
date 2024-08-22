#include "stdafx.h"

#include "blender_luma.h"

CBlender_luma::CBlender_luma() { description.CLS = 0; }

CBlender_luma::~CBlender_luma()
{
}

void CBlender_luma::Compile(CBlender_Compile& C)
{
	IBlender::Compile(C);

	switch (C.iElement)
	{
	case 0:
		C.r_Pass("stub_screen_space", "luma_tester", FALSE, FALSE, FALSE);
		C.r_dx10Texture("s_image", r2_RT_generic0);	
		C.r_dx10Texture("s_position", r2_RT_P);
        C.r_dx10Texture("s_normal", r2_RT_N);
		C.r_dx10Texture("s_diffuse", r2_RT_albedo);
		C.r_dx10Texture("s_luma_prev", "$user$luma_avg");
		C.r_dx10Texture("s_blue_noise", "engine\\blue_noise");

		jitter(C);

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break; 
	case 1:
		C.r_Pass("stub_screen_space", "luma_tester2", FALSE, FALSE, FALSE);
		C.r_dx10Texture("s_image", r2_RT_generic0);	
		C.r_dx10Texture("s_position", r2_RT_P);
        C.r_dx10Texture("s_normal", r2_RT_N);
		C.r_dx10Texture("s_diffuse", r2_RT_albedo);
		C.r_dx10Texture("s_luma", "$user$luma_tex");

		jitter(C);

		C.r_dx10Sampler("smp_nofilter");
		C.r_dx10Sampler("smp_rtlinear");
		C.r_End();
		break;   	       
	}
}