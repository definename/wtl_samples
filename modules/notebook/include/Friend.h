#pragma once

//////////////////////////////////////////////////////////////////////////
// Interface of the Friend class.
//

class Friend
{
	//
	// Construction and destruction.
	//
public:
	//! Default constructor.
	Friend();
	//! Constructor.
	Friend(const std::wstring&, const std::wstring&, const std::wstring&, const std::wstring&);
	//! Destructor.
	~Friend();

	//
	// Public interface
	//
public:
	//! Get Address data
	std::wstring GetAddress() const;
	//! Get Birthday data
	std::wstring GetBirthday() const;
	//! Get Name data
	std::wstring GetName() const;
	//! Get Patronymic data
	std::wstring GetPatronymic() const;
	//! Get Phone data
	std::wstring GetPhone() const;
	//! Get Surname data
	std::wstring GetSurname() const;
	//! Set Address data
	void SetAddress(const std::wstring&);
	//! Set Birthday data
	void SetBirthday(const std::wstring&);
	//! Set Name data
	void SetName(const std::wstring&);
	//! Set Patronymic data
	void SetPatronymic(const std::wstring&);
	//! Set Phone data
	void SetPhone(const std::wstring&);
	//! Set Surname data
	void SetSurname(const std::wstring&);

	//
	// Private data members.
	//
private:
	//! Friend address
	std::wstring address_;
	//! Friend birthday
	std::wstring birthday_;
	//! Friend name
	std::wstring name_;
	//! Friend patronymic
	std::wstring patronymic_;
	//! Friend phone
	std::wstring phone_;
	//! Friend surname
	std::wstring surname_;

	//
	// Private interface.
	//
private:
	friend class boost::serialization::access;
	//! Serialization method
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & address_;
		ar & birthday_;
		ar & name_;
		ar & patronymic_;
		ar & phone_;
		ar & surname_;
	}
};