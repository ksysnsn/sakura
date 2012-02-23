/*!	@file
	@brief �t�@�C���I�[�v���_�C�A���O�{�b�N�X

	@author Norio Nakatani
	@date	1998/08/10 �쐬
*/
/*
	Copyright (C) 1998-2001, Norio Nakatani
	Copyright (C) 2001, genta
	Copyright (C) 2002, YAZAKI, Moca
	Copyright (C) 2003, ryoji
	Copyright (C) 2004, genta, MIK
	Copyright (C) 2005, ryoji
	Copyright (C) 2006, Moca, ryoji
	Copyright (C) 2008, nasukoji

	This source code is designed for sakura editor.
	Please contact the copyright holder to use this code for other purpose.
*/

class CDlgOpenFile;

#ifndef _CDLGOPENFILE_H_
#define _CDLGOPENFILE_H_

#include <windows.h>
#include "CShareData.h"
#include "CEol.h"
#include "COsVersionInfo.h"	// 2005.11.02 ryoji

// 2005.10.29 ryoji
// Windows 2000 version of OPENFILENAME.
// The new version has three extra members.
// See commdlg.h
#if (_WIN32_WINNT >= 0x0500)
struct OPENFILENAMEZ : public OPENFILENAME {
};
#else
struct OPENFILENAMEZ : public OPENFILENAME {
  void *        pvReserved;
  DWORD         dwReserved;
  DWORD         FlagsEx;
};
#define OPENFILENAME_SIZE_VERSION_400 sizeof(OPENFILENAME)
#endif // (_WIN32_WINNT >= 0x0500)


/*!	�t�@�C���I�[�v���_�C�A���O�{�b�N�X

	@date 2002.2.17 YAZAKI CShareData�̃C���X�^���X�́ACProcess�ɂЂƂ���̂݁B
*/
class SAKURA_CORE_API CDlgOpenFile
{
public:
	/*
	||  Constructors
	*/
	CDlgOpenFile();
	~CDlgOpenFile();
	/*
	||  Attributes & Operations
	*/
	void Create( HINSTANCE, HWND, const char*, const char*, const char** = NULL,const char** = NULL);
	//void Create( HINSTANCE, HWND, const char*, const char* );
	//	2002/08/21 moca	�����ǉ�
	BOOL DoModal_GetOpenFileName( char*, bool bSetCurDir = false );	/* �J���_�C�A���O ���[�_���_�C�A���O�̕\�� */
	//	2002/08/21 30,2002 moca	�����ǉ�
	BOOL DoModal_GetSaveFileName( char*, bool bSetCurDir = false );	/* �ۑ��_�C�A���O ���[�_���_�C�A���O�̕\�� */
	BOOL DoModalOpenDlg( char* , int*, BOOL* );	/* �J���_�C�A�O ���[�_���_�C�A���O�̕\�� */
	//	Feb. 9, 2001 genta	�����ǉ�
	//	Jul. 26, 2003 ryoji BOM�p�����ǉ�
	BOOL DoModalSaveDlg( char* , int*, CEol*, BOOL* );	/* �ۑ��_�C�A���O ���[�_���_�C�A���O�̕\�� */

//	INT_PTR DispatchEvent(	HWND, UINT, WPARAM, LPARAM );	/* �_�C�A���O�̃��b�Z�[�W���� */

	HINSTANCE		m_hInstance;	/* �A�v���P�[�V�����C���X�^���X�̃n���h�� */
	HWND			m_hwndParent;	/* �I�[�i�[�E�B���h�E�̃n���h�� */
	HWND			m_hWnd;			/* ���̃_�C�A���O�̃n���h�� */

	DLLSHAREDATA*	m_pShareData;
//	int				m_nSettingType;

	char			m_szDefaultWildCard[_MAX_PATH + 1];	/* �u�J���v�ł̍ŏ��̃��C���h�J�[�h�i�ۑ����̊g���q�⊮�ł��g�p�����j */
	char			m_szInitialDir[_MAX_PATH + 1];		/* �u�J���v�ł̏����f�B���N�g�� */
	OPENFILENAMEZ	m_ofn;							/* 2005.10.29 ryoji OPENFILENAMEZ�u�t�@�C�����J���v�_�C�A���O�p�\���� */
	int				m_nCharCode;					/* �����R�[�h */
//	char			m_szHelpFile[_MAX_PATH + 1];
//	int				m_nHelpTopicID;
	CEol			m_cEol;	//	Feb. 9, 2001 genta
	bool			m_bUseEol;	//	Feb. 9, 2001 genta

	//	Jul. 26, 2003 ryoji BOM
	BOOL			m_bBom;	//!< BOM��t���邩�ǂ���
	bool			m_bUseBom;	//!< BOM�̗L����I������@�\�𗘗p���邩�ǂ���

	TCHAR			m_szPath[_MAX_PATH];	// �g���q�̕⊮�����O�ōs�����Ƃ��̃t�@�C���p�X	// 2006.11.10 ryoji

protected:
	/*
	||  �����w���p�֐�
	*/

	//	May 29, 2004 genta �G���[�������܂Ƃ߂� (advised by MIK)
	void	DlgOpenFail(void);

	// 2005.11.02 ryoji OS �o�[�W�����Ή��� OPENFILENAME �������p�֐�
	static COsVersionInfo m_cOsVer;
	BOOL IsOfnV5( void ) { return ( m_cOsVer.GetVersion() && (m_cOsVer.IsWin2000_or_later() || m_cOsVer.IsWinMe()) ); }
	void InitOfn( OPENFILENAMEZ& );

	// 2005.11.02 ryoji �������C�A�E�g�ݒ菈��
	static void InitLayout( HWND hwndOpenDlg, HWND hwndDlg, HWND hwndBaseCtrl );

	// 2005.10.29 ryoji �R���{�{�b�N�X�̃h���b�v�_�E��������
	static void OnCmbDropdown( HWND hwnd );

	// 2006.09.03 Moca �t�@�C���_�C�A���O�̃G���[���
	//! ���g���C�@�\�t�� GetOpenFileName
	BOOL GetOpenFileNameRecover( OPENFILENAMEZ& ofn );
	//! ���g���C�@�\�t�� GetOpenFileName
	BOOL GetSaveFileNameRecover( OPENFILENAMEZ& ofn );

	BOOL CheckPathLengthOverflow( const char *pszPath, int nLength, BOOL bErrDisp = TRUE );	// 2008.11.23 nasukoji	�w��̃t�@�C���p�X�̃o�b�t�@�I�[�o�[�t���[���`�F�b�N����

	friend UINT_PTR CALLBACK OFNHookProc( HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam );
};



///////////////////////////////////////////////////////////////////////
#endif /* _CDLGOPENFILE_H_ */


/*[EOF]*/