#ifndef ADIM_H_
#define ADIM_H_

#include "AdimBase.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

const string defaultKeycodeFilename = "keycode.txt";
const string defaultWorkbookFilename = "word.txt";
const string defaultCandidateNumberFilename = "Candidate_Number.txt";

class Adim : public AdimBase
{
public:
	Adim(const string& keycodeFilename = defaultKeycodeFilename,
		const string& workbookFilename = defaultWorkbookFilename,
		const string& candidateNumberFilename = defaultCandidateNumberFilename,
		size_t numberOfQuestion = 2,
		bool randomQuestion = true,
		size_t firstQuestionNumber = 0,
		int sizeOfCharacterCode = 2) : nowNumberOfQuestion_(0), complete_(false)
	{
		initAdim(keycodeFilename,workbookFilename,candidateNumberFilename,
			numberOfQuestion,randomQuestion,firstQuestionNumber,sizeOfCharacterCode);
	}
	//���������s��
	void initAdim(const string& keycodeFilename, const string& workbookFilename,
		const string& candidateNumberFilename, 
		size_t numberOfQuestion = 2,
		bool randomQuestion = true,
		size_t firstQuestionNumber = 0,
		int sizeOfCharacterCode = 2);
	//�L�[�{�[�h������͂����R�[�h��n��
	int InputCharacter(char code);

	string GetNowSentenceOfInputtedAgateQuestionRed() const;
	string GetNowSentenceOfInputtedConvertQuestionRed() const;
	string GetNowSentenceOfInputtedAgateQuestionBlue() const;
	string GetNowSentenceOfInputtedConvertQuestionBlue() const;
	bool isFinishTyping() { return complete_; } //game���I���������ǂ���
	enum{ FAILURE = 0, SUCCESS = 1, COMPLETE = 2 };

private:
	vector<size_t> numberOfQuestionArray_; //���ԍ�
	size_t numberOfQuestion_; //�o�肷���萔
	size_t nowNumberOfQuestion_; //���݉���ڂ�
	bool randomQuestion_; //���������_���ɏo�肷�邩
	bool complete_; //�������ׂđł��I�������true
};

#endif