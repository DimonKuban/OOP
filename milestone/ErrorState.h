// Header file. Contains constructor, member functions, helper operator, error message declaration
// File ErrorState.h
// Date: 2018/03/22
// Author: Dmitrii Korolevskii

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
namespace AMA{
	class ErrorState{
		char* errorMessage;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState&) = delete;
		ErrorState& operator=(const ErrorState&) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream&, ErrorState&);
}
#endif