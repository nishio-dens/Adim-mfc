#include <string>
#include <algorithm>
#include <iostream>
#include "Adim.h"

void Adim::initAdim(const string& keycodeFilename, const string& workbookFilename,
		const string& candidateNumberFilename, 
		size_t numberOfQuestion ,
		bool randomQuestion ,size_t firstQuestionNumber,
		int sizeOfCharacterCode) 
{
	complete_ = false;
	ReadKeycode(keycodeFilename);
	ReadWorkbook(workbookFilename);
	InitKeycodeTableCandidateNumber();
	SetKeycodeTableCandidateNumberFilename(candidateNumberFilename);
	ReadKeycodeTableCandidateNumber();
	numberOfQuestion_ = numberOfQuestion;
	
	do{
		if( randomQuestion ) {
			for(int i=0; i < GetNumberOfWorkbookElement() ; ++i ) {
				numberOfQuestionArray_.push_back(i);
			}
			random_shuffle( numberOfQuestionArray_.begin(),
				numberOfQuestionArray_.end() );		
		}else {
			for(int i=firstQuestionNumber; i < GetNumberOfWorkbookElement() ; ++i ) {
				numberOfQuestionArray_.push_back(i);
			}
			for(int i=0; i < GetNumberOfWorkbookElement() ; ++i ) {
				numberOfQuestionArray_.push_back(i);
			}
		}
	}while( numberOfQuestionArray_.size() < GetNumberOfWorkbookElement() );

	SetQuestion( numberOfQuestionArray_[0] );
	SetSizeOfCharacterCode(sizeOfCharacterCode);
}

//[�ԋp�l]
//2 ���� ��蕶�ł��I����� COMPLETE
//1 ���� ���̂܂ܑ��s SUCCESS
//0 ���s FAILURE
int Adim::InputCharacter(char code)
{
	int result = InputTypewordFromKeyboard(code);

	if( result == COMPLETE ) { //��蕶��ł��I�����
		nowNumberOfQuestion_++;
		int num = nowNumberOfQuestion_;
		
		if( num >= GetNumberOfWorkbookElement() )
			num = 0;
		SetQuestion( numberOfQuestionArray_[num] );
		SaveKeycodeTableCandidateNumber(); //�L�[�R�[�h�e�[�u���̕ۑ�
		if( nowNumberOfQuestion_ >= numberOfQuestion_ ){
			complete_ = true;
		}
	}
	return result;
}

string Adim::GetNowSentenceOfInputtedAgateQuestionRed() const
{
	size_t tmpPlus = GetNextAgateCaharcter().size();
	if( GetOneCharCompleteFlag() ) {
			return GetNowSentenceOfAgateQuestion().substr(0,
				GetNowPositionOfQuestion() + tmpPlus );
	}
	return GetNowSentenceOfAgateQuestion().substr(0,
		GetNowPositionOfQuestion() );
}

string Adim::GetNowSentenceOfInputtedConvertQuestionRed() const
{
	return GetNowSentenceOfConvertQuestion().substr(0,
		GetCompleteInputtedRoman().size() + 1 );
}

string Adim::GetNowSentenceOfInputtedAgateQuestionBlue() const
{
	size_t tmpPlus = GetNextAgateCaharcter().size();
	if( !GetOneCharCompleteFlag() ) {
		return GetNowSentenceOfAgateQuestion().substr(0,
			GetNowPositionOfQuestion() - tmpPlus );
	}
	return GetNowSentenceOfAgateQuestion().substr(0,GetNowPositionOfQuestion() );
}
string Adim::GetNowSentenceOfInputtedConvertQuestionBlue() const
{
	return GetCompleteInputtedRoman();
}

//temporary
//int main()
//{
//	using std::cout;
//	using std::endl;
//
//	Adim hoge;
//	try {
//		hoge.TempDebugFunction();
//	}catch(const exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}