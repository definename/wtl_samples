#pragma once

#include "Friend.h"

//////////////////////////////////////////////////////////////////////////
// Interface of the FriendManager class.
//

class FriendManager
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	FriendManager(FileNameType&);
	//! Destructor.
	~FriendManager();

	//! Push new Friend to end container
	void AddFriend(const Friend&);
	//! Return friend by index
	Friend GetFriend(const int&) const;
	//! Return number of elements in the container 
	int GetNoteBookSize() const;
	//! Get data from archive
	void Load();
	//! Remove friend from container
	void Remove(const int&);
	//! Put data to archive
	void Save();
	//! Erase current Friend and push new Friend to container
	void SetFriend(const int&, const Friend&);
	//! Fill our notebook-container from other Friend container
	void SetNotebook(const std::vector<Friend>&);

	//
	// Private data members
	//
private:
	//! File name for serialization/deserialization
	FileNameType fileName_;
	//! Container for work with note book
	std::vector<Friend> notebook_;
};

// type of pointer to friend manager
typedef boost::shared_ptr<FriendManager> FriendManagerPtr;