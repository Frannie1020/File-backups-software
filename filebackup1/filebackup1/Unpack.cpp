#include "Unpack.h"

bool Unpack::Init()
{
	cout << "���������ļ�·��: ";
	cin >> m_szFileName;

	//�򿪴���ļ�
	m_hFile = CreateFile(m_szFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (m_hFile == INVALID_HANDLE_VALUE)
	{
		cout << "�ļ��޷���" << endl;
		CloseHandle(m_hFile);
		return 0;
	}

	char tag[] = "ABC1234";
	char ch[8];
	DWORD dwBytesRead;
	ReadFile(m_hFile, ch, sizeof(ch), &dwBytesRead, NULL);
	if (strcmp(tag, ch) != 0)  //�ж��Ƿ�Ϊ����ļ�
	{
		cout << "���ļ����ܽ��" << endl;
		CloseHandle(m_hFile);
		return 0;
	}

	strcpy_s(m_szIndexName, m_szFileName);
	m_szIndexName[strlen(m_szIndexName) - 8] = '\0';
	strcat_s(m_szIndexName, ".txt");   //��ȡ�����ļ�·��

	//�������ļ������������ļ�Ҫ�ʹ���ļ�����ͬ
	m_hFileIndex = CreateFile(m_szIndexName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (m_hFileIndex == INVALID_HANDLE_VALUE)
	{
		cout << "�޷��������ļ�" << endl;
		CloseHandle(m_hFileIndex);
		return 0;
	}

	cout << "��������Ŀ���ļ���·��: ";
	cin >> m_szDirName;
	CreateDirectory(m_szDirName, NULL); //����Ŀ¼

	return 1;
}

bool Unpack::UnpackFile()
{
	DWORD buff[BUFSIZE];  //������
	DWORD dwBytesRead, dwBytesWritten, dwIndexRead;  //��¼��ȡ��д���ļ����ֽ���

	cout << "�����" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while (ReadFile(m_hFileIndex, &m_Index, sizeof(m_Index), &dwIndexRead, NULL))  //��ʼ��ȡ�����ļ�
	{
		if (dwIndexRead <= 0)
			break;

		char fName[MAX_PATH];  //�����洢�����ĸ����ļ���·��
		strcpy_s(fName, m_szDirName);
		strcat_s(fName, "\\");
		strcat_s(fName, m_Index.FileName);

		//���������ĸ����ļ�
		HANDLE hTmpFile = CreateFile(fName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hTmpFile == INVALID_HANDLE_VALUE)
		{
			cout << "�ļ��޷���" << endl;
			CloseHandle(hTmpFile);
			return 0;
		}
		cout << m_Index.FileName << '\t' << m_Index.Size << " B" << endl;  //������������ļ�����Ϣ
		unsigned int len;  //�����洢ÿ�ζ�ȡ�ļ����ֽ���
		do
		{//��ʼ������ļ��������д������ĸ����ļ�
			len = m_Index.Size < BUFSIZE ? m_Index.Size : BUFSIZE;
			if (ReadFile(m_hFile, buff, len, &dwBytesRead, NULL))
			{
				WriteFile(hTmpFile, buff, dwBytesRead, &dwBytesWritten, NULL);
				m_Index.Size -= len;
			}

		} while (m_Index.Size > 0);
		CloseHandle(hTmpFile);

	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "����ɹ�" << endl;

	CloseHandle(m_hFile);
	CloseHandle(m_hFileIndex);
	return 1;
}