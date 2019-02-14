#ifndef ANIMALS_HPP_INCLUDED
#define ANIMALS_HPP_INCLUDED

#include<ostream>
#include<string>
#include<stdexcept>
#include<boost/date_time/gregorian/gregorian.hpp>
#include<boost/regex.hpp>
//Represent a veterinarian or trainer

class Contact
{
public:
	Contact();
	Contact(const std::string& name, const std::string& phone) :name_(name)
	{
		setPhone(phone);
	}
	std::string name()const { return name_; }
	std::string phone() const { return phone_; }
	void setPhone(const std::string& phone)
	{
		using namespace std;
		using namespace boost;
		//Use Boost.Regex to verify that phone
		//Has the form (ddd)ddd-dddd
		static regex pattern("\\([0-9]{3}\\)[0-9]{3}-[0-9]{4}");
		if (!regex_match(phone, pattern))
		{
			throw runtime_error(string("bad phone number:") + phone);
		}
		phone_ = phone;
	}
	~Contact();

private:
	std::string name_;
	std::string phone_;
};

Contact::Contact()
{
}

Contact::~Contact()
{
}

//Compare two Contact for equality; used in 
bool operator ==(const Contact& lhs, const Contact& rhs)
{
	return lhs.name() == rhs.name() && lhs.phone() == rhs.phone();
}

//Writes a Contact to an ostream 
std::ostream& operator <<(std::ostream& out, const Contact& contact)
{
	out << contact.name() << " " << contact.phone();
	return out;
}

class Animal
{
public:
	Animal();
	Animal(const std::string& name,
		const std::string& species,
		const std::string& dob,
		const Contact& vet,
		const Contact& trainer) :name_(name), species_(species), trainer_(trainer)
	{
		setDateOfBirth(dob);
	};
	~Animal();
	//Getters 
	std::string name() const { return name_; }
	std::string species() const { return species_; }
	boost::gregorian::date dateOfBirth() const { return dob_; }
	Contact veterinarian() const { return vet_; }
	Contact trainer() const { return trainer_; }

	//Setter
	void setName(const std::string& name) { name_ = name; }
	void setSpecies(const std::string& species) { species_ = species; }
	void setDateOfBirth(const std::string& dob)
	{
		dob_ = boost::gregorian::from_string(dob);
	}
	void setVeterinarian(const Contact& vet) { vet_ = vet; }
	void setTrainer(const Contact& trainer) { trainer_ = trainer; }
private:

	std::string name_;
	std::string species_;
	boost::gregorian::date dob_;
	Contact vet_;
	Contact trainer_;
};

Animal::Animal()
{
}

Animal::~Animal()
{
}
bool operator ==(const Animal& lhs, const Animal& rhs)
{
	return lhs.name() == rhs.name() &&
		lhs.species() == rhs.species() &&
		lhs.dateOfBirth() == rhs.dateOfBirth() &&
		lhs.veterinarian() == rhs.veterinarian() &&
		lhs.trainer() == rhs.trainer();
}
std::ostream& operator<<(std::ostream& out, const Animal& animal)
{
	out << "Animal{\n"
		<< "name=" << animal.name() << ";\n"
		<< "species=" << animal.species() << ";\n"
		<< "date of birth=" << animal.dateOfBirth() << ";\n"
		<< "veternarian=" << animal.veterinarian() << ";\n"
		<< "trainer=" << animal.trainer() << ";\n"
		<< "}";
	return out;
}

#endif // ANIMALS_HPP_INCLUDED
