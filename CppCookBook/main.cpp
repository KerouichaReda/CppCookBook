#include<exception>
#include <iostream>
#include<stdexcept>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<tinyxml.h>
#include"animal.hpp"

//Extracts the content of an XML element that contains onlu text
const char* textValue(TiXmlElement* e)
{
	TiXmlNode *first = e->FirstChild();
	if (first!=0 && first == e->LastChild() && first->Type()==TiXmlNode::NodeType::TINYXML_TEXT)
	{
		// the element e has single child, of type TEXT 
		// return the child's
		return first->Value();
	}
	else
	{
		throw std::runtime_error(std::string("bad ") + e->Value() + " element");
	}
} 
// Construct a Contact from a "veterinarian" or "trainer" element  
Contact nodeToContact(TiXmlElement* contact)
{
	using namespace std;
	const char *name, *phone;
	if (contact->FirstChild()==0 && (name =contact->Attribute("name")) && (phone=contact->Attribute("phone")) )
	{
		//The element contact is childless and has "name"
		//and "phone" attribute; use these values to 
		//construct a Contact
		return Contact(name, phone);
	}
	else
	{
		throw runtime_error(string("bad ") + contact->Value() + " element");
	}
}
// construct an Animal from an "animal" element
Animal nodeToAnimal(TiXmlElement* animal)
{
	using namespace std;
	// verify that animal correspond to an "animal" element
	if (strcmp(animal->Value(), "animal")!=0)
	{
		throw runtime_error(string("bad animal: ") + animal->Value());
	}

	Animal result;//Return value
	TiXmlElement* element = animal->FirstChildElement();

	//Read name
	if (element && strcmp(element->Value(), "name") == 0)
	{
		//The first child element of animal is a "name"
		//element; use its text value to set the name of result
		result.setName(textValue(element));
	}
	else {
		throw runtime_error("no name attribute");
	}

	//Read species
	element = element->NextSiblingElement();
	if (element && strcmp(element->Value(),"species")==0)
	{
		//The second child element of animal is a "species"
		//element; use its text value to set the species of result 
		result.setSpecies(textValue(element));
	}
	else
	{
		throw runtime_error("no Species attribute");
	}
	//Read date of birth
	element = element->NextSiblingElement();
	if (element && strcmp(element->Value(),"dateOfBirth")==0)
	{
		//The third child element of animal is a "dateOfbirth
		//element us eits text value to set the data of bith 
		//of result
		result.setDateOfBirth(textValue(element));
	}
	else
	{
		throw runtime_error("no dateOfBirth attribute");
	}
	//Read veterinarian 
	element = element->NextSiblingElement();
	if (element && strcmp(element->Value(), "veterinarian ") == 0)
	{
		// The fourth child element of animal is a "veterinarian"
		// element; use it to construct a Contact object and
		// set result's veterinarian
		result.setVeterinarian(nodeToContact(element));
	}
	else
	{
		throw runtime_error("no Species attribute");
	}
	//Read trainer
	element = element->NextSiblingElement();
	if (element && strcmp(element->Value(), "trainer") == 0)
	{
		// The fourth child element of animal is a "veterinarian"
		// element; use it to construct a Contact object and
		// set result's veterinarian
		result.setTrainer(nodeToContact(element));
	}
	else
	{
		throw runtime_error("no trainer attribute");
	}

	//Check that there are no more children 
	element = element->NextSiblingElement();
	if (element!=0)
	{
		throw std::runtime_error(string("unexpected element:") + element->Value());
	}
	return result;
}



int main()
{
	using namespace std;
	try
	{
		vector<Animal>animaList;
		TiXmlDocument doc("animals.xml");
		if (!doc.LoadFile())
		{
			throw runtime_error("bad parse");
		}
		//verify that root is an animal list
		TiXmlElement* root = doc.RootElement();
		if (strcmp(root->Value(), "animalList") != 0)
		{
			throw runtime_error(string("bad root: ") + root->Value());
		}
		// Traverse children of root, populating the list 
		//of animals 
		for (TiXmlElement* animal =root->FirstChildElement(); animal ; animal=animal->NextSiblingElement())
		{
			animaList.push_back(nodeToAnimal(animal));
		}
		//Print the animals name
		for (vector<Animal>::size_type i = 0 ,n=animaList.size(); i < n; i++)
		{
			cout << animaList[i] << endl;
		}
		
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		return EXIT_FAILURE;
	}
	std::getchar();
	return 0;
}