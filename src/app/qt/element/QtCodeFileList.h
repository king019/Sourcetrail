#ifndef QT_CODE_FILE_LIST
#define QT_CODE_FILE_LIST

#include <memory>
#include <vector>

#include <QFrame>
#include <QScrollArea>

#include "utility/types.h"

class QtCodeFile;
class TokenLocationFile;

class QtCodeFileList: public QScrollArea
{
	Q_OBJECT

public:
	QtCodeFileList(QWidget* parent = 0);
	virtual ~QtCodeFileList();

	virtual QSize sizeHint() const;

	void addCodeSnippet(
		uint startLineNumber,
		const std::string& code,
		const TokenLocationFile& locationFile
	);

	void clearCodeSnippets();

	const std::vector<Id>& getActiveTokenIds() const;
	void setActiveTokenIds(const std::vector<Id>& activeTokenIds);

	const std::vector<std::string>& getErrorMessages() const;
	void setErrorMessages(const std::vector<std::string>& errorMessages);

	bool getShowMaximizeButton() const;
	void setShowMaximizeButton(bool show);

private:
	void updateFiles();

	std::shared_ptr<QFrame> m_frame;
	std::vector<std::shared_ptr<QtCodeFile>> m_files;

	std::vector<Id> m_activeTokenIds;
	std::vector<std::string> m_errorMessages;
	bool m_showMaximizeButton;
};

#endif // QT_CODE_FILE_LIST
