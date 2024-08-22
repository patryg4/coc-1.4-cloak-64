#pragma once

class CBlender_luma : public IBlender
{
public:
	virtual LPCSTR getComment() { return "LUMA!"; }
	virtual BOOL canBeDetailed() { return FALSE; }
	virtual BOOL canBeLMAPped() { return FALSE; }

	virtual void Compile(CBlender_Compile& C);

	CBlender_luma();
	virtual ~CBlender_luma();
};