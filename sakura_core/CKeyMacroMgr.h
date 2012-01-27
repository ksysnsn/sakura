/*!	@file
	@brief �L�[�{�[�h�}�N��

	@author Norio Nakatani
*/
/*
	Copyright (C) 1998-2001, Norio Nakatani
	Copyright (C) 2001, aroka
	Copyright (C) 2002, YAZAKI, genta

	This source code is designed for sakura editor.
	Please contact the copyright holder to use this code for other purpose.
*/

#ifndef _CKEYMACROMGR_H_
#define _CKEYMACROMGR_H_

#include <windows.h>
#include "CMacroManagerBase.h"

/*
struct KeyMacroData {
	int		m_nFuncID;
	LPARAM	m_lParam1;
};
*/

//#define MAX_STRLEN			70
//#define MAX_KEYMACRONUM		10000
/*-----------------------------------------------------------------------
�N���X�̐錾
-----------------------------------------------------------------------*/
//! �L�[�{�[�h�}�N��
/*!
	�L�[�{�[�h�}�N���N���X
*/
class CKeyMacroMgr : public CMacroManagerBase
{
public:
	/*
	||  Constructors
	*/
	CKeyMacroMgr();
	~CKeyMacroMgr();

	/*
	||  Attributes & Operations
	*/
	void ClearAll( void );				/* �L�[�}�N���̃o�b�t�@���N���A���� */
	void Append( int , LPARAM, class CEditView* pcEditView );		/* �L�[�}�N���̃o�b�t�@�Ƀf�[�^�ǉ� */
	void Append( class CMacro* macro );		/* �L�[�}�N���̃o�b�t�@�Ƀf�[�^�ǉ� */
//	int GetMacroNum() { return m_nKeyMacroDataArrNum; };
	
	/* �L�[�{�[�h�}�N�����܂Ƃ߂Ď�舵�� */
	BOOL SaveKeyMacro( HINSTANCE hInstance, const char* pszPath) const;	/* CMacro�̗���A�L�[�{�[�h�}�N���ɕۑ� */
	//@@@2002.2.2 YAZAKI PPA.DLL�A��/�i�V�����̂���virtual�ɁB
	//	2007.07.20 genta flags�ǉ�
	virtual void ExecKeyMacro( class CEditView* pcEditView, int flags ) const;	/* �L�[�{�[�h�}�N���̎��s */
	virtual BOOL LoadKeyMacro( HINSTANCE hInstance, const char* pszPath );		/* �L�[�{�[�h�}�N�����t�@�C������ǂݍ��� */
	virtual BOOL LoadKeyMacroStr( HINSTANCE hInstance, const char* pszCode );		/* �L�[�{�[�h�}�N���𕶎��񂩂�ǂݍ��� */
	
	/* �L�[�{�[�h�}�N�����ǂݍ��ݍς݂��m�F���� */
	//	Apr. 29, 2002 genta
	//	IsReady��CMacroManagerBase�ֈړ�

	// Apr. 29, 2002 genta
	static CMacroManagerBase* Creator(const char*);
	static void declare(void);

protected:
//	int				m_nKeyMacroDataArrNum;
	//	Apr. 29, 2002 genta
	//	m_nReady��CMacroManagerBase�ֈړ�

	class CMacro*	m_pTop;	//	�擪�ƏI�[��ێ�
	class CMacro*	m_pBot;
};



///////////////////////////////////////////////////////////////////////
#endif /* _CKEYMACROMGR_H_ */


/*[EOF]*/