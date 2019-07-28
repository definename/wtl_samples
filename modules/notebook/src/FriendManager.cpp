#include "pch.h"
#include "FriendManager.h"

//////////////////////////////////////////////////////////////////////////
// Implementation of the FriendManager class.
//

FriendManager::FriendManager(FileNameType& fileName)
	: fileName_(fileName)
{

}

FriendManager::~FriendManager()
{

}

void FriendManager::AddFriend(const Friend& friendForPush)
{
	notebook_.push_back(friendForPush);
}

Friend FriendManager::GetFriend(const int& index) const
{
	if(static_cast<int>(notebook_.size()) <= index)
	{
		BOOST_THROW_EXCEPTION(std::runtime_error("Get record: \"ID\" out of range"));
	}
	return notebook_[index];
}

int FriendManager::GetNoteBookSize() const
{
	return notebook_.size();
}

void FriendManager::Load()
{
	std::ifstream ifs(fileName_.c_str(), std::ios::in);
	if(!ifs)
	{
		BOOST_THROW_EXCEPTION(std::runtime_error("Load: File archive could not be opened"));
	}
	boost::archive::text_iarchive ia(ifs);
	ia >> notebook_;
	ifs.close();
}

void FriendManager::Remove(const int& index)
{
	if(static_cast<int>(notebook_.size()) <= index)
	{
		BOOST_THROW_EXCEPTION(std::runtime_error("Remove record: \"ID\" out of range"));
	}
	notebook_.erase(notebook_.begin() + index);
}

void FriendManager::Save()
{
	std::ofstream ofs(fileName_.c_str(), std::ios::out);
	if(!ofs)
	{
		BOOST_THROW_EXCEPTION(std::runtime_error("Save: File archive could not be opened"));
	}
	boost::archive::text_oarchive oa(ofs);
	oa << notebook_; 
	ofs.close();
}

void FriendManager::SetFriend(const int& index, const Friend& friendForPush)
{
	if(static_cast<int>(notebook_.size()) <= index)
	{
		BOOST_THROW_EXCEPTION(std::runtime_error("Set: record \"ID\" out of range"));
	}
	notebook_.erase(notebook_.begin() + index);
	notebook_.insert(notebook_.begin() + index, friendForPush);
}

void FriendManager::SetNotebook(const std::vector<Friend>& otherNotebook)
{
	notebook_ = otherNotebook;
}