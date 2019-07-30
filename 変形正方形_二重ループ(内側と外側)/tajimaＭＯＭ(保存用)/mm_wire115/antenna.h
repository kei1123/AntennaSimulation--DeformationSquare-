//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//
//			�A���e�i�`��w�b�_�[�@�@antenna.h
//				�_�C�|�[���A���e�i
//
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//				�v�Z
//////////////////////////////////////////////////////////////////////////////////
void Calculation(void)
{
	//========================================================
	//			���[�J���ϐ�
	//========================================================
	//--�J�E���^
	int i,j,k,m,n,f;

	//--�v�Z�Ŏg�p����ϐ�
	double rrx , rry , rrz;											//�Z�O�����g�n�_
	double drx , dry , drz;											//�Z�O�����g�I�_
	double ssx , ssy , ssz;											//�Z�O�����g�̒P�ʃx�N�g��
	double dcl;														//�Z�O�����g����

	//--�G�������g���֌W�i���C���[�{���j
	int n_array;													//�_�C�|�[���̖{��

	//--�e�����̕�����
	int nbun_pole1,nbun_pole2;										//�_�C�|�[���̕�����
	int nbun_pole1_1,nbun_pole2_1;									//�_�C�|�[���̕�����
	int setsugo_pole;

	int nbun_poleh;													//�_�C�|�[���̕�����
	//--�e���̃Z�O�����g��
	int n_pole;														//�_�C�|�[���̃Z�O�����g��

	//--�݌v�l�֌W
	double h_pole,h;
	double r_pole1,r_pole2,r_polec,r_poled,r_pole;					//�_�C�|�[���̒�������
	double r_pole1_1,r_pole2_1,r_polec_1,r_poled_1,r_pole_1;		//�_�C�|�[���̒����O��
	double rsetsugo_pole;											//�ڍ�����
	double wire_radius;												//���C���[���a
	double M_PI=3.14159265358979323846264338327950288;
	double radius;

	//========================================================
	//			���ˊE�v�Z�ݒ�		�P�ʁF(deg)
	//========================================================
	//--�v�Z���[�h
	AXMODE = 0;			//(0=�ӌŒ�, 1=�ƌŒ�)

	//--�ώ�
	DegDelta =  1.0;	//���ݕ�("0.0"�֎~)
	DegStart =  -90.0;	//�����p
	DegWidth =  180.0;	//�͈�

	//--�Œ莲
	FixAngle =  90.0;	//�Œ�p�x

	//========================================================
	//			�݌v���g��		FREQ0	(f0)	�P�ʁF(Hz)
	//			���d���g��		USEF	(f)		�P�ʁF(Hz)
	//========================================================

	for(k=0;k<1;k++){						//���͒�

		for(n=0;n<1;n++){					//�ۓ��f�q��
			
			for(f=0;f<1;f++){				//���g��


	//--�݌v���g���ݒ�
	FREQ0 = 3.0 * pow(10.0,9.0);

	//--�d�������ݒ�@
	USEF  = FREQ0 * (1.00+(0.001*f));		//f���Ƃ�ɂ͌W����ύX

	//--�݌v���g���̎��R��Ԕg��
	RAMDA0= C/FREQ0;

	//========================================================
	//			�`��l��`
	//			������RAMDA0����@�W���Œl��`(������)
	//========================================================

	r_polec = (1.02570 + 0.000001*k) * RAMDA0;					//���͒�
	r_poled = (0.08840 + 0.000001*n) * RAMDA0;					//�����̔���

	r_polec_1 = (2.023212 + 0.0000001*k) * RAMDA0;				//�����`���͒�2.0356
	r_poled_1 = (0.320584 + 0.0000001*n) * RAMDA0;				//�����̔���0.1547


	//--������
	r_pole1 = r_polec/4 - r_poled;								//�΂ߐ�
	r_pole2 = 2.0 * r_poled;									//����

	//--�����O
	r_pole1_1 = r_polec_1/4 - r_poled_1;						//�΂ߐ�
	r_pole2_1 = 2.0 * r_poled_1;								//����


	r_pole = (r_pole1/sqrt(2.0)) + r_poled;						//�X�^�[�g�n�_

	r_pole_1 = (r_pole1_1/sqrt(2.0)) + r_poled_1;				//�X�^�[�g�n�_

	rsetsugo_pole = sqrt(pow(r_pole-r_poled-r_pole_1+r_poled_1,2) + pow(r_pole2-r_pole2_1,2));		//�ڍ������̒���

	double angle;
	angle = atan2( r_pole-r_poled-r_pole_1+r_poled_1 , r_pole2-r_pole2_1);


	//--���C���[���a
	wire_radius = RAMDA0/200;
	
	h = 0.0625 * RAMDA0;										//����
	h_pole = h;

	//========================================================
	//			�S���C���[��	NWIR
	//			�Z�O�����g��	NSEG
	//			���d�_��		NFED
	//			�S�d���v�Z�_��	NSEG0
	//			�y���א�		NLOAD		
	//========================================================

	//--�S���C���[���ݒ�
	n_array = 27;
	NWIR = n_array;

	//--���������͓��~
	nbun_pole1 = int(r_pole1/(RAMDA0 * 0.02));	//�΂ߐ�
	nbun_pole2 = int(r_pole2/(RAMDA0 * 0.02));	//����

	//--���������͊O�~
	nbun_pole1_1 = int(r_pole1_1/(RAMDA0 * 0.02));	//�΂ߐ�
	nbun_pole2_1 = int(r_pole2_1/(RAMDA0 * 0.02));	//����

	//�_�C�|�[���̕�����
	nbun_poleh = int(h_pole/(RAMDA0 * 0.02));	//����

	setsugo_pole = int(rsetsugo_pole/(RAMDA0 * 0.02));

	//--�S�Z�O�����g���ݒ�
	n_pole = int(2.0*(nbun_pole1*4+4 + 2.0*nbun_pole2+2) + 2.0*(nbun_pole1_1*4+4 + 2.0*nbun_pole2_1+2) + 2.0*(setsugo_pole+2) + 2.0*nbun_poleh+2);
	NSEG = n_pole;								//�S�Z�O�����g��

	//--�S�d���v�Z�_��  [NSEG0=NSEG-NWIR]	�������������폜�@�s��
	NSEG0 = NSEG - NWIR;

	//--���d�_��
	NFED = 1;

	//--�C���s�[�_���X���א�
	NLOAD = 0;

	//========================================================
	//			�z��m�ۂƏ�����
	//			[���ˊE�v�Z�ݒ�,NWIR,NSEG,NFED,NLOAD]
	//				�ݒ��Ɋ֐��Ăяo��
	//			�������������폜�@�s��
	//========================================================
	MakeMatAll();								//�z��m��(���R�����g�A�E�g�֎~��)
	Initialization();							//�z��ƌv�Z�p�ϐ��̏�����


	//========================================================
	//			�o�̓t�@�C���p�̃p�����[�^
	//			PARA1 �� PARA2 �ɒl����͂���D
	//========================================================
	PARA1 = r_polec/RAMDA0;
	PARA2 =	r_poled/RAMDA0;
	PARA3 = h/RAMDA0;								
	PARA4 = (r_pole-r_poled) / r_pole;
	PARA5 = FixAngle;

	//========================================================
	//			�݌v�l����		�P�ʁF(m)
	//			�Z�O�����g�n�_	RX[ ] , RY[ ] , RZ[ ] 
	//			�P�ʃx�N�g��	SX[ ] , SY[ ] , SZ[ ]
	//			�Z�O�����g��	SEGL[ ]
	//========================================================

	i=0;

//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------���~�̍\��-----------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------����̎΂ߐ�---------------------------------------------------------
	for(j = 0; j < nbun_pole1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -r_pole + cos(M_PI/4.0)*(r_pole1/nbun_pole1)*(j+0);		//�n�_�ʒu�v�Zx
		rry = 0 + sin(M_PI/4.0)*(r_pole1/nbun_pole1)*(j+0);				//�n�_�ʒu�v�Zy
		rrz = h_pole;													//�n�_�ʒu�v�Zz
		drx = -r_pole + cos(M_PI/4.0)*(r_pole1/nbun_pole1)*(j+1);		//�I�_�ʒu�v�Zx
		dry = 0 + sin(M_PI/4.0)*(r_pole1/nbun_pole1)*(j+1);				//�I�_�ʒu�v�Zy
		drz = h_pole;													//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}



//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2 + (j+0)*r_pole2/nbun_pole2;			//�n�_�ʒu�v�Zx
		rry = r_pole - r_poled;									//�n�_�ʒu�v�Zy
		rrz = h_pole;											//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2 + (j+1)*r_pole2/nbun_pole2;			//�I�_�ʒu�v�Zx
		dry = r_pole - r_poled;									//�I�_�ʒu�v�Zy
		drz = h_pole;											//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );						//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;									//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;									//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;									//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;											//�n�_�ʒux
		RY[i] = rry;											//�n�_�ʒuy
		RZ[i] = rrz;											//�n�_�ʒuz
		SX[i] = ssx;											//�P�ʃx�N�g��x
		SY[i] = ssy;											//�P�ʃx�N�g��y
		SZ[i] = ssz;											//�P�ʃx�N�g��z
		SEGL[i] = dcl;											//�Z�O�����g��
		i++;
	}


//------------------------------------------------��̉���---------------------------------------------------------
	for(j = 0; j < nbun_pole2; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2 + (j+0)*r_pole2/nbun_pole2;			//�n�_�ʒu�v�Zx
		rry = r_pole - r_poled;									//�n�_�ʒu�v�Zy
		rrz = h_pole;											//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2 + (j+1)*r_pole2/nbun_pole2;			//�I�_�ʒu�v�Zx
		dry = r_pole - r_poled;									//�I�_�ʒu�v�Zy
		drz = h_pole;											//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );						//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;									//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;									//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;									//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;											//�n�_�ʒux
		RY[i] = rry;											//�n�_�ʒuy
		RZ[i] = rrz;											//�n�_�ʒuz
		SX[i] = ssx;											//�P�ʃx�N�g��x
		SY[i] = ssy;											//�P�ʃx�N�g��y
		SZ[i] = ssz;											//�P�ʃx�N�g��z
		SEGL[i] = dcl;											//�Z�O�����g��
		i++;
	}

//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = 0.5*r_pole2 + (j+0)*r_pole1*cos(M_PI/4)/nbun_pole1;		//�n�_�ʒu�v�Zx
		rry = r_pole-r_poled - (j+0)*r_pole1*sin(M_PI/4)/nbun_pole1;	//�n�_�ʒu�v�Zy
		rrz = h_pole;													//�n�_�ʒu�v�Zz
		drx = 0.5*r_pole2 + (j+1)*r_pole1*cos(M_PI/4)/nbun_pole1;		//�I�_�ʒu�v�Zx
		dry = r_pole-r_poled - (j+1)*r_pole1*sin(M_PI/4)/nbun_pole1;	//�I�_�ʒu�v�Zy
		drz = h_pole;													//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}

//------------------------------------------------�E��̎΂ߐ�---------------------------------------------------------
	for(j = 0; j < nbun_pole1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = 0.5*r_pole2 + (j+0)*r_pole1*cos(M_PI/4)/nbun_pole1;			//�n�_�ʒu�v�Zx
		rry = r_pole-r_poled - (j+0)*r_pole1*sin(M_PI/4)/nbun_pole1;		//�n�_�ʒu�v�Zy
		rrz = h_pole;														//�n�_�ʒu�v�Zz
		drx = 0.5*r_pole2 + (j+1)*r_pole1*cos(M_PI/4)/nbun_pole1;			//�I�_�ʒu�v�Zx
		dry = r_pole-r_poled - (j+1)*r_pole1*sin(M_PI/4)/nbun_pole1;		//�I�_�ʒu�v�Zy
		drz = h_pole;		//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );									//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;												//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;												//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;												//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;														//�n�_�ʒux
		RY[i] = rry;														//�n�_�ʒuy
		RZ[i] = rrz;														//�n�_�ʒuz
		SX[i] = ssx;														//�P�ʃx�N�g��x
		SY[i] = ssy;														//�P�ʃx�N�g��y
		SZ[i] = ssz;														//�P�ʃx�N�g��z
		SEGL[i] = dcl;														//�Z�O�����g��
		i++;
	}

//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = r_pole - (j+0)*r_pole1*cos(M_PI/4)/nbun_pole1;		//�n�_�ʒu�v�Zx
		rry = 0 - (j+0)*r_pole1*sin(M_PI/4)/nbun_pole1;				//�n�_�ʒu�v�Zy
		rrz = h_pole;												//�n�_�ʒu�v�Zz
		drx = r_pole - (j+1)*r_pole1*cos(M_PI/4)/nbun_pole1;		//�I�_�ʒu�v�Zx
		dry = 0 - (j+1)*r_pole1*sin(M_PI/4)/nbun_pole1;				//�I�_�ʒu�v�Zy
		drz = h_pole;												//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );						//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;									//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;									//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;									//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;											//�n�_�ʒux
		RY[i] = rry;											//�n�_�ʒuy
		RZ[i] = rrz;											//�n�_�ʒuz
		SX[i] = ssx;											//�P�ʃx�N�g��x
		SY[i] = ssy;											//�P�ʃx�N�g��y
		SZ[i] = ssz;											//�P�ʃx�N�g��z
		SEGL[i] = dcl;											//�Z�O�����g��
		i++;
	}




//------------------------------------------------x��y�����}�C�i�X�ɂ����Ƃ�------------------------------------------------------------

	for(j = 0; j < nbun_pole1+nbun_pole2+nbun_pole1+1+1+1; ++j){
		//--�v�Z���ʑ��
		RX[i] = -RX[j];											//�n�_�ʒux
		RY[i] = -RY[j];											//�n�_�ʒuy
		RZ[i] = RZ[j];											//�n�_�ʒuz
		SX[i] = -SX[j];											//�P�ʃx�N�g��x
		SY[i] = -SY[j];											//�P�ʃx�N�g��y
		SZ[i] = SZ[j];											//�P�ʃx�N�g��z
		SEGL[i] = SEGL[j];										//�Z�O�����g��
		i++;
	}

	int temp = i;

//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------�O�~�̍\��-----------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------����̎΂ߐ�---------------------------------------------------------
	for(j = 0; j < nbun_pole1_1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -r_pole_1 + cos(M_PI/4.0)*(r_pole1_1/nbun_pole1_1)*(j+0);		//�n�_�ʒu�v�Zx
		rry = 0 + sin(M_PI/4.0)*(r_pole1_1/nbun_pole1_1)*(j+0);				//�n�_�ʒu�v�Zy
		rrz = h_pole;														//�n�_�ʒu�v�Zz
		drx = -r_pole_1 + cos(M_PI/4.0)*(r_pole1_1/nbun_pole1_1)*(j+1);		//�I�_�ʒu�v�Zx
		dry = 0 + sin(M_PI/4.0)*(r_pole1_1/nbun_pole1_1)*(j+1);				//�I�_�ʒu�v�Zy
		drz = h_pole;														//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}



//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2_1 + (j+0)*r_pole2_1/nbun_pole2_1;			//�n�_�ʒu�v�Zx
		rry = r_pole_1 - r_poled_1;										//�n�_�ʒu�v�Zy
		rrz = h_pole;													//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2_1 + (j+1)*r_pole2_1/nbun_pole2_1;			//�I�_�ʒu�v�Zx
		dry = r_pole_1 - r_poled_1;										//�I�_�ʒu�v�Zy
		drz = h_pole;													//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}


//------------------------------------------------��̉���---------------------------------------------------------
	for(j = 0; j < nbun_pole2_1; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2_1 + (j+0)*r_pole2_1/nbun_pole2_1;			//�n�_�ʒu�v�Zx
		rry = r_pole_1 - r_poled_1;										//�n�_�ʒu�v�Zy
		rrz = h_pole;													//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2_1 + (j+1)*r_pole2_1/nbun_pole2_1;			//�I�_�ʒu�v�Zx
		dry = r_pole_1 - r_poled_1;										//�I�_�ʒu�v�Zy
		drz = h_pole;													//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}

//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = 0.5*r_pole2_1 + (j+0)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1;			//�n�_�ʒu�v�Zx
		rry = r_pole_1-r_poled_1 - (j+0)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1;	//�n�_�ʒu�v�Zy
		rrz = h_pole;															//�n�_�ʒu�v�Zz
		drx = 0.5*r_pole2_1 + (j+1)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1;			//�I�_�ʒu�v�Zx
		dry = r_pole_1-r_poled_1 - (j+1)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1;	//�I�_�ʒu�v�Zy
		drz = h_pole;															//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );										//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;													//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;													//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;													//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;															//�n�_�ʒux
		RY[i] = rry;															//�n�_�ʒuy
		RZ[i] = rrz;															//�n�_�ʒuz
		SX[i] = ssx;															//�P�ʃx�N�g��x
		SY[i] = ssy;															//�P�ʃx�N�g��y
		SZ[i] = ssz;															//�P�ʃx�N�g��z
		SEGL[i] = dcl;															//�Z�O�����g��
		i++;
	}

//------------------------------------------------�E��̎΂ߐ�---------------------------------------------------------
	for(j = 0; j < nbun_pole1_1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = 0.5*r_pole2_1 + (j+0)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1;			//�n�_�ʒu�v�Zx
		rry = r_pole_1-r_poled_1 - (j+0)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1;	//�n�_�ʒu�v�Zy
		rrz = h_pole;															//�n�_�ʒu�v�Zz
		drx = 0.5*r_pole2_1 + (j+1)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1;			//�I�_�ʒu�v�Zx
		dry = r_pole_1-r_poled_1 - (j+1)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1;	//�I�_�ʒu�v�Zy
		drz = h_pole;															//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );										//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;													//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;													//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;													//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;															//�n�_�ʒux
		RY[i] = rry;															//�n�_�ʒuy
		RZ[i] = rrz;															//�n�_�ʒuz
		SX[i] = ssx;															//�P�ʃx�N�g��x
		SY[i] = ssy;															//�P�ʃx�N�g��y
		SZ[i] = ssz;															//�P�ʃx�N�g��z
		SEGL[i] = dcl;															//�Z�O�����g��
		i++;
	}

//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = r_pole_1 - (j+0)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1;			//�n�_�ʒu�v�Zx
		rry = 0 - (j+0)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1;					//�n�_�ʒu�v�Zy
		rrz = h_pole;														//�n�_�ʒu�v�Zz
		drx = r_pole_1 - (j+1)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1;			//�I�_�ʒu�v�Zx
		dry = 0 - (j+1)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1;					//�I�_�ʒu�v�Zy
		drz = h_pole;														//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );									//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;												//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;												//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;												//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;														//�n�_�ʒux
		RY[i] = rry;														//�n�_�ʒuy
		RZ[i] = rrz;														//�n�_�ʒuz
		SX[i] = ssx;														//�P�ʃx�N�g��x
		SY[i] = ssy;														//�P�ʃx�N�g��y
		SZ[i] = ssz;														//�P�ʃx�N�g��z
		SEGL[i] = dcl;														//�Z�O�����g��
		i++;
	}

//--------------------------------------------------------------------------------------------------------------------
//------------------------------------------------����̎΂ߐ�---------------------------------------------------------
	for(j = 0; j < nbun_pole1_1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -(-r_pole_1 + cos(M_PI/4.0)*(r_pole1_1/nbun_pole1_1)*(j+0));		//�n�_�ʒu�v�Zx
		rry = -(0 + sin(M_PI/4.0)*(r_pole1_1/nbun_pole1_1)*(j+0));				//�n�_�ʒu�v�Zy
		rrz = h_pole;														//�n�_�ʒu�v�Zz
		drx = -(-r_pole_1 + cos(M_PI/4.0)*(r_pole1_1/nbun_pole1_1)*(j+1));		//�I�_�ʒu�v�Zx
		dry = -(0 + sin(M_PI/4.0)*(r_pole1_1/nbun_pole1_1)*(j+1));				//�I�_�ʒu�v�Zy
		drz = h_pole;														//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}



//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -(-0.5*r_pole2_1 + (j+0)*r_pole2_1/nbun_pole2_1);			//�n�_�ʒu�v�Zx
		rry = -(r_pole_1 - r_poled_1);										//�n�_�ʒu�v�Zy
		rrz = h_pole;													//�n�_�ʒu�v�Zz
		drx = -(-0.5*r_pole2_1 + (j+1)*r_pole2_1/nbun_pole2_1);			//�I�_�ʒu�v�Zx
		dry = -(r_pole_1 - r_poled_1);										//�I�_�ʒu�v�Zy
		drz = h_pole;													//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}


//------------------------------------------------��̉���---------------------------------------------------------
	for(j = 0; j < nbun_pole2_1; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -(-0.5*r_pole2_1 + (j+0)*r_pole2_1/nbun_pole2_1);			//�n�_�ʒu�v�Zx
		rry = -(r_pole_1 - r_poled_1);										//�n�_�ʒu�v�Zy
		rrz = h_pole;													//�n�_�ʒu�v�Zz
		drx = -(-0.5*r_pole2_1 + (j+1)*r_pole2_1/nbun_pole2_1);			//�I�_�ʒu�v�Zx
		dry = -(r_pole_1 - r_poled_1);										//�I�_�ʒu�v�Zy
		drz = h_pole;													//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}

//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -(0.5*r_pole2_1 + (j+0)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1);			//�n�_�ʒu�v�Zx
		rry = -(r_pole_1-r_poled_1 - (j+0)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1);	//�n�_�ʒu�v�Zy
		rrz = h_pole;															//�n�_�ʒu�v�Zz
		drx = -(0.5*r_pole2_1 + (j+1)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1);			//�I�_�ʒu�v�Zx
		dry = -(r_pole_1-r_poled_1 - (j+1)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1);	//�I�_�ʒu�v�Zy
		drz = h_pole;															//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );										//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;													//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;													//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;													//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;															//�n�_�ʒux
		RY[i] = rry;															//�n�_�ʒuy
		RZ[i] = rrz;															//�n�_�ʒuz
		SX[i] = ssx;															//�P�ʃx�N�g��x
		SY[i] = ssy;															//�P�ʃx�N�g��y
		SZ[i] = ssz;															//�P�ʃx�N�g��z
		SEGL[i] = dcl;															//�Z�O�����g��
		i++;
	}

//------------------------------------------------�E��̎΂ߐ�---------------------------------------------------------
	for(j = 0; j < nbun_pole1_1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -(0.5*r_pole2_1 + (j+0)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1);			//�n�_�ʒu�v�Zx
		rry = -(r_pole_1-r_poled_1 - (j+0)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1);	//�n�_�ʒu�v�Zy
		rrz = h_pole;															//�n�_�ʒu�v�Zz
		drx = -(0.5*r_pole2_1 + (j+1)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1);			//�I�_�ʒu�v�Zx
		dry = -(r_pole_1-r_poled_1 - (j+1)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1);	//�I�_�ʒu�v�Zy
		drz = h_pole;															//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );										//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;													//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;													//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;													//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;															//�n�_�ʒux
		RY[i] = rry;															//�n�_�ʒuy
		RZ[i] = rrz;															//�n�_�ʒuz
		SX[i] = ssx;															//�P�ʃx�N�g��x
		SY[i] = ssy;															//�P�ʃx�N�g��y
		SZ[i] = ssz;															//�P�ʃx�N�g��z
		SEGL[i] = dcl;															//�Z�O�����g��
		i++;
	}

//------------------------------------------------�I�[�o�[���b�v---------------------------------------------------------
	for(j = 0; j < 1; ++j){

		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -(r_pole_1 - (j+0)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1);			//�n�_�ʒu�v�Zx
		rry = -(0 - (j+0)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1);					//�n�_�ʒu�v�Zy
		rrz = h_pole;														//�n�_�ʒu�v�Zz
		drx = -(r_pole_1 - (j+1)*r_pole1_1*cos(M_PI/4)/nbun_pole1_1);			//�I�_�ʒu�v�Zx
		dry = -(0 - (j+1)*r_pole1_1*sin(M_PI/4)/nbun_pole1_1);					//�I�_�ʒu�v�Zy
		drz = h_pole;														//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );									//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;												//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;												//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;												//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;														//�n�_�ʒux
		RY[i] = rry;														//�n�_�ʒuy
		RZ[i] = rrz;														//�n�_�ʒuz
		SX[i] = ssx;														//�P�ʃx�N�g��x
		SY[i] = ssy;														//�P�ʃx�N�g��y
		SZ[i] = ssz;														//�P�ʃx�N�g��z
		SEGL[i] = dcl;														//�Z�O�����g��
		i++;
	}

//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------�ڍ�����-------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------�I�[�o�[���b�v:�ڍ�����------------------------------------------------------------
	for(j = 0; j < 1; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2_1 + (j+1)*r_pole2_1/nbun_pole2_1;			//�n�_�ʒu�v�Zx
		rry = r_pole_1-r_poled_1; 										//�n�_�ʒu�v�Zy
		rrz = h;														//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2_1 + (j+0)*r_pole2_1/nbun_pole2_1; 			//�I�_�ʒu�v�Zx
		dry = r_pole_1-r_poled_1;										//�I�_�ʒu�v�Zy
		drz = h;														//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );								//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;											//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;											//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;											//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;													//�n�_�ʒux
		RY[i] = rry;													//�n�_�ʒuy
		RZ[i] = rrz;													//�n�_�ʒuz
		SX[i] = ssx;													//�P�ʃx�N�g��x
		SY[i] = ssy;													//�P�ʃx�N�g��y
		SZ[i] = ssz;													//�P�ʃx�N�g��z
		SEGL[i] = dcl;													//�Z�O�����g��
		i++;
	}

printf("%d\n",rsetsugo_pole);
//------------------------------------------------�ڍ�����------------------------------------------------------------

	for(j = 0; j < setsugo_pole; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = (-0.5*r_pole2_1) - (j+0)*cos(angle)*rsetsugo_pole/setsugo_pole;							//�n�_�ʒu�v�Zx
		rry = (r_pole_1-r_poled_1) + (j+0)*sin(angle)*rsetsugo_pole/setsugo_pole;						//�n�_�ʒu�v�Zy
		rrz = h;																						//�n�_�ʒu�v�Zz
		drx = (-0.5*r_pole2_1) - (j+1)*cos(angle)*rsetsugo_pole/setsugo_pole;							//�I�_�ʒu�v�Zx
		dry = (r_pole_1-r_poled_1) + (j+1)*sin(angle)*rsetsugo_pole/setsugo_pole;						//�I�_�ʒu�v�Zy
		drz = h;																						//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );						//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;									//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;									//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;									//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;											//�n�_�ʒux
		RY[i] = rry;											//�n�_�ʒuy
		RZ[i] = rrz;											//�n�_�ʒuz
		SX[i] = ssx;											//�P�ʃx�N�g��x
		SY[i] = ssy;											//�P�ʃx�N�g��y
		SZ[i] = ssz;											//�P�ʃx�N�g��z
		SEGL[i] = dcl;											//�Z�O�����g��
		i++;
	}
	
//------------------------------------------------�I�[�o�[���b�v:�ڍ�����------------------------------------------------------------
	for(j = 0; j < 1; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2 + (j+0)*r_pole2/nbun_pole2;			//�n�_�ʒu�v�Zx
		rry = r_pole-r_poled; 									//�n�_�ʒu�v�Zy
		rrz = h;												//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2 + (j+1)*r_pole2/nbun_pole2;; 		//�I�_�ʒu�v�Zx
		dry = r_pole-r_poled;									//�I�_�ʒu�v�Zy
		drz = h;												//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );						//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;									//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;									//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;									//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;											//�n�_�ʒux
		RY[i] = rry;											//�n�_�ʒuy
		RZ[i] = rrz;											//�n�_�ʒuz
		SX[i] = ssx;											//�P�ʃx�N�g��x
		SY[i] = ssy;											//�P�ʃx�N�g��y
		SZ[i] = ssz;											//�P�ʃx�N�g��z
		SEGL[i] = dcl;											//�Z�O�����g��
		i++;
	}

//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------���ׂĂ̔���---------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------���˔�------------------------------------------------------------

	for(j = 0; j < 2.0*(nbun_pole1+nbun_pole2+nbun_pole1+1+1+1 + nbun_pole1_1+nbun_pole2_1+nbun_pole1_1+1+1+1) + setsugo_pole+2; ++j){
		//--�v�Z���ʑ��
		RX[i] = RX[j];											//�n�_�ʒux
		RY[i] = RY[j];											//�n�_�ʒuy
		RZ[i] = -RZ[j];											//�n�_�ʒuz
		SX[i] = SX[j];											//�P�ʃx�N�g��x
		SY[i] = SY[j];											//�P�ʃx�N�g��y
		SZ[i] = -SZ[j];											//�P�ʃx�N�g��z
		SEGL[i] = SEGL[j];										//�Z�O�����g��
		i++;
	}


//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------���d�_-----------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------�I�[�o�[���b�v:���d�_(-z)------------------------------------------------------------
	for(j = 0; j < 1; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2 + (j+1)*r_pole2/nbun_pole2;						//�n�_�ʒu�v�Zx
		rry = r_pole-r_poled; 												//�n�_�ʒu�v�Zy
		rrz = -h;															//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2 + (j+0)*r_pole2/nbun_pole2; 						//�I�_�ʒu�v�Zx
		dry = r_pole-r_poled;												//�I�_�ʒu�v�Zy
		drz = -h;															//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );						//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;									//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;									//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;									//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;											//�n�_�ʒux
		RY[i] = rry;											//�n�_�ʒuy
		RZ[i] = rrz;											//�n�_�ʒuz
		SX[i] = ssx;											//�P�ʃx�N�g��x
		SY[i] = ssy;											//�P�ʃx�N�g��y
		SZ[i] = ssz;											//�P�ʃx�N�g��z
		SEGL[i] = dcl;											//�Z�O�����g��
		i++;
	}

//------------------------------------------------���d�_------------------------------------------------------------

	for(j = 0; j < nbun_poleh*2; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2;												//�n�_�ʒu�v�Zx
		rry = r_pole - r_poled;											//�n�_�ʒu�v�Zy
		rrz = -h + (j+0)*h/nbun_poleh;									//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2;												//�I�_�ʒu�v�Zx
		dry = r_pole - r_poled;											//�I�_�ʒu�v�Zy
		drz = -h + (j+1)*h/nbun_poleh;									//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );						//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;									//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;									//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;									//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;											//�n�_�ʒux
		RY[i] = rry;											//�n�_�ʒuy
		RZ[i] = rrz;											//�n�_�ʒuz
		SX[i] = ssx;											//�P�ʃx�N�g��x
		SY[i] = ssy;											//�P�ʃx�N�g��y
		SZ[i] = ssz;											//�P�ʃx�N�g��z
		SEGL[i] = dcl;											//�Z�O�����g��
		i++;
	}
	
//------------------------------------------------�I�[�o�[���b�v:���d�_(+z)------------------------------------------------------------
	for(j = 0; j < 1; ++j){
		//--�n�_ �I�_ �Z�O�����g���v�Z
		rrx = -0.5*r_pole2 + (j+0)*r_pole2/nbun_pole2;			//�n�_�ʒu�v�Zx
		rry = r_pole-r_poled; 									//�n�_�ʒu�v�Zy
		rrz = h;												//�n�_�ʒu�v�Zz
		drx = -0.5*r_pole2 + (j+1)*r_pole2/nbun_pole2;; 		//�I�_�ʒu�v�Zx
		dry = r_pole-r_poled;									//�I�_�ʒu�v�Zy
		drz = h;												//�I�_�ʒu�v�Zz
		//--�Z�O�����g�� �P�ʕ����x�N�g���̊e�����̌v�Z
		dcl = sqrt( pow( (rrx-drx),2 )
				  + pow( (rry-dry),2 )
				  + pow( (rrz-drz),2 ) );						//�Z�O�����g���v�Z
		ssx = (drx-rrx) / dcl;									//�P�ʃx�N�g��x
		ssy = (dry-rry) / dcl;									//�P�ʃx�N�g��y
		ssz = (drz-rrz) / dcl;									//�P�ʃx�N�g��z
		//--�v�Z���ʑ��
		RX[i] = rrx;											//�n�_�ʒux
		RY[i] = rry;											//�n�_�ʒuy
		RZ[i] = rrz;											//�n�_�ʒuz
		SX[i] = ssx;											//�P�ʃx�N�g��x
		SY[i] = ssy;											//�P�ʃx�N�g��y
		SZ[i] = ssz;											//�P�ʃx�N�g��z
		SEGL[i] = dcl;											//�Z�O�����g��
		i++;
	}




//-------------------------------------------------------------------------------------------------------------------
	//========================================================
	//			�e�Z�O�����g�̃��C���[���a����	�P�ʁF(m)
	//			RA[ ]		���C���[���a
	//========================================================
	for(i = 0; i < NSEG; ++i){
		RA[i] = wire_radius;	
	}

	//========================================================
	//			�e�G�������g(���C���[)���̃Z�O�����g��
	//			SEGN[ ]
	//========================================================
	
	//�@���@�I�[�o�[���b�v���݂Ł@��
	SEGN[0] = nbun_pole1 +1;
	SEGN[1] = nbun_pole2 +1;
	SEGN[2] = nbun_pole1 +1;
	SEGN[3] = nbun_pole1 +1;
	SEGN[4] = nbun_pole2 +1;
	SEGN[5] = nbun_pole1 +1;

	SEGN[6] = nbun_pole1_1 +1;
	SEGN[7] = nbun_pole2_1 +1;
	SEGN[8] = nbun_pole1_1 +1;
	SEGN[9] = nbun_pole1_1 +1;
	SEGN[10] = nbun_pole2_1 +1;
	SEGN[11] = nbun_pole1_1 +1;

	SEGN[12] = setsugo_pole +2;

	SEGN[13] = nbun_pole1 +1;
	SEGN[14] = nbun_pole2 +1;
	SEGN[15] = nbun_pole1 +1;
	SEGN[16] = nbun_pole1 +1;
	SEGN[17] = nbun_pole2 +1;
	SEGN[18] = nbun_pole1 +1;

	SEGN[19] = nbun_pole1_1 +1;
	SEGN[20] = nbun_pole2_1 +1;
	SEGN[21] = nbun_pole1_1 +1;
	SEGN[22] = nbun_pole1_1 +1;
	SEGN[23] = nbun_pole2_1 +1;
	SEGN[24] = nbun_pole1_1 +1;

	SEGN[25] = setsugo_pole +2;

	SEGN[26] = nbun_poleh*2 +2;

	//========================================================
	//			���d�֌W�ݒ�
	//			���d�ʒu		FEDP[ ]
	//			���d�d��		FEDV[ ]
	//
	//			���ʒu  FEDP[ ]
	//					[���d�������ʒu]-[���d���������C���[(���Ԗ�)]
	//			���d��  FEDV[ ]
	//				�@��P���d�̓d��
	//					�s���t���d��p����ꍇ   -2�~(1+j0)[V]
	//					���t���d��p����ꍇ     -1�~(1+j0)[V]
	//				�A���˔t���_�C�|�[����(���˔t�����t���d�A���e�i)
	//					��P���d(���˔\��)   -1�~(1+j0)[V]
	//					��Q���d(���˔���)    1�~(1+j0)[V]
	//						(���˔̕\�Ɨ��ŋ��d�ʑ����t�ɂ���)
	//				�B��P���d���C���[�W�@�̏ꍇ
	//					���̋��d�_���C���[�W�@��K�p����D
	//				�C��P���d���C���[�W�@��p���Ȃ��ꍇ
	//					���̋��d�_���C���[�W�@��p���Ȃ��D
	//				�D�������d�̓d���E�ʑ�������
	//					��P���d�͏����@�A��K�p
	//					��P���d�ȊO�Ő�����s���D
	//========================================================
	FEDP[0] = SEGN[0]*8-8 + SEGN[6]*8-8 + SEGN[1]*4-4 + SEGN[7]*4-4 + (SEGN[24]-2)/2 -1+1;
	FEDV[0] = -2.0 * Complex( 1.0 , 0.0 );

	//========================================================
	//			�C���s�[�_���X���׊֌W�ݒ�
	//			���׈ʒu		LOADP[ ]
	//			���גl�@		LOADZ[ ]
	//
	//			���ʒu    LOADP[ ]
	//					[���ׂ������ʒu]-[���ׂ��������C���[(���Ԗ�)]
	//			�����גl�@LOADZ[ ]  (50����ڑ�����ꍇ)
	//				�@���˔ɒ�R��t����ꍇ		 -2�~(50+j0)[��]
	//				�A���C���̓r���ɒ�R��t����ꍇ -1�~(50+j0)[��]
	//				�B�ڑ��Ώۂɂ�炸�C�l�́u�}�C�i�X(-)�v�ɂȂ�
	//								(��R�l�̓x�N�g���ł͖�������)
	//========================================================

////----------------�S�Z�O�����g����SEGN�̍��v����v���邩�m�F
//double n_seg_free=0;
//for(j=0;j<n_array;j++){
//printf("SEGN[%d]=%d\n",j,SEGN[j]);
//n_seg_free+=SEGN[j];
//}
//printf("n_array=%d\n",n_array);
//printf("n_seg_free=%d\n",n_seg_free);
//printf("n_pole=%d\n",n_pole);
////----------------------------------------------------

	//========================================================
	//			�e�Z�O�����g����̕��ˏ�Ԃ�ݒ�(�������ːݒ�)
	//			RAD_MODE[ ] = 1 or 0
	//				(0 : ���˃J�b�g   1 : �ʏ�̕���)
	//			�������őS��RAD_MODE[ ]=1 �ɐݒ�ς�
	//========================================================


	//========================================================
	//			�d���E���ˊE�v�Z
	//========================================================	
	ConfCheck();				//�`�󌟍�
	MakeZmn();					//Zmn�쐬
	MakeCurrent();				//�d���v�Z
	MakePhase();				//�d���ʑ��v�Z
	Radiation();				//���ˊE�v�Z
	LapsedTime();				//�o�ߎ��Ԏ擾

	//========================================================
	//			�f�[�^�o��
	//========================================================	
	OutputConf();				//�`��o��
	OutputCurrent();			//�d���o��
	OutputRad();				//���ˊE�o��
	OutputChara();				//�����f�[�^�o��


	//========================================================
	//			�z��̊J��
	//========================================================	
	DelMatAll();				//�z��J��(���R�����g�A�E�g�֎~��)
}

}
}
}
//============================================================================
//					�ϐ��Ɣz��ꗗ
//============================================================================
//
//--�`�� ���d
//		double	FREQ0					�݌v���g��f0
//		double	RAMDA0					�݌v���g���̎��R��Ԕg��
//		double	USEF					���d���g��
//		int		NWIR					�S���C���[��
//		int		NSEG					�S�Z�O�����g��
//		int		NFED					�S���d�_��
//		int		NSEG0					�S�d���v�Z�_��
//		int		NLOAD					��R�����א�
//--���ˊE�v�Z
//		int		AXMODE   				(0=�ӌŒ�, 1=�ƌŒ�)	
//		double	DegDelta 				���ݕ�
//		double	DegStart 				�����p
//		double	DegWidth 				�͈�
//		double	FixAngle 				�Œ莲�p�x
//--���ԑ���
//		int		la_min	la_sec			�� �b
//--�v�Z�񂵗p�p�����[�^
//		double	PARA1,PARA2				�p�����[�^�@�ƇA
//--�`��z��
//		double	RX[ ]  RY[ ]  RZ[ ]		�e�Z�O�����g�̎n�_
//		double�@SX[ ]  SY[ ]  SZ[ ]		�P�ʃx�N�g���̐���
//		double	SEGL[ ]	RA[ ]			�e�Z�O�����g�̒��� ���a�@		
//		int�@	SEGN[ ]					�e���C���[�̃Z�O�����g��
//		int		FEDP[ ]					�e���d�ʒu
//		complex	FEDV[ ]					�e���d�d��
//		int		RAD_MODE[ ]				�e�Z�O�����g�̕��˃��[�h
//		int		LOADP[ ]				�e�C���s�[�_���X���׈ʒu
//		complex LOADZ[ ]				�e�C���s�[�_���X���גl
//--�d���z��
//		complex Zmn[ ][ ]				�C���s�[�_���X�s��	
//		complex Im[ ]					�d�����z
//		double  PhaseIm[ ]				�d���̈ʑ�
//--���̓C���s�[�_���X
//		complex Zin[ ]					�e���d�_�̓��̓C���s�[�_���X
//		double  VSWR_50[ ]  VSWR_75[ ]	�e���d�_��50����75���ɑ΂���VSWR
//--���ˊE�z��
//		complex TRAD[ ] FRAD[ ]			E�Ƃ�E�ӂ̕��ˊE
//		complex RRAD[ ] LRAD[ ]			ER ��EL �̕��ˊE
//		double TPHASE[ ] FPHASE[ ]		E�Ƃ�E�ӂ̈ʑ�
//		double RPHASE[ ] LPHASE[ ]		ER ��EL �̈ʑ�
//		double TGAI[ ] FGAI[ ]			E�Ƃ�E�ӂ̗���
//		double TFGAI[ ]					E�Ƃ�E�ӂ̍��v�̗���
//		double RLGAI[ ]					ER ��EL �̍��v�̗���
//		double RGAI[ ] LGAI[ ]			ER ��EL �̗���
//		double TPAT[ ] FPAT[ ]			E�Ƃ�E�ӂ̃p�^�[��
//		double RPAT[ ] LPAT[ ]			ER ��EL �̃p�^�[��
//		double AR[ ]					����
//--��{�����萔
//		double PI						��
//		double C						����
//		double e0						�^�󒆂̓�������0
//		double u0						�^�󒆂̗U�d����0
//		double R						1.0 �Œ�
//--���ȗ��p
//		complex J						�����P�ʁ@J=��-1
//--�ϕ��p
//		int GaussTenNo					�K�E�X�ϕ����_  [ 4�Œ�]�i�ʏ�p�j
//		int GaussTenSpe					�K�E�X�ϕ����_��[40�Œ�]�i���ٓ_�p�j
//--�v�Z�p
//		double k0						k0
//		complex uair					u(air)
//		double Beta;					��
//============================================================================