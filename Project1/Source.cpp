#include <iostream>
#include <vector>
#include <string>
class Card {
public:
	Card() = default;
	Card(const std::string& initial_name, const unsigned& initial_id, const
		unsigned& initial_image_id) : name(initial_name), id(initial_id),
		image_id(initial_image_id) {}
	void set_name(const std::string& new_name)
	{
		this->name = new_name;
	}
	void set_id(const unsigned& new_id)
	{
		this->id = new_id;
	}
	void set_image_id(const unsigned& new_image_id)
	{
		this->image_id = new_image_id;
	}
	unsigned get_id() const
	{
		return this->id;
	}
	unsigned get_image_id() const
	{
		return this->image_id;
	}
	std::string get_name() const
	{
		return this->name;
	}
	virtual void print() const
	{
		std::cout << "Name: " << this->name << ", ID: " << this->id << ", ImageID: " << this->image_id;
	}
	virtual ~Card() {}
protected:
	std::string name;
	unsigned id;
	unsigned image_id;
};
class HeroCard : virtual public Card
{
public:
	HeroCard() = default;
	HeroCard(const std::string& initial_name, const unsigned& initial_id, const
		unsigned& initial_image_id,
		const unsigned& initial_attack_power, const unsigned&
		initial_defence_power) :
		Card(initial_name, initial_id, initial_image_id),
		attack_power(initial_attack_power), defence_power(initial_defence_power)
	{}
	void set_attack_power(const unsigned& new_attack_power)
	{
		this->attack_power = new_attack_power;
	}
	void set_defence_power(const unsigned& new_defence_power)
	{
		this->defence_power = new_defence_power;
	}
	unsigned get_attack_power() const
	{
		return this->attack_power;
	}
	unsigned get_defence_power() const
	{
		return this->defence_power;
	}
	void print() const override
	{
		Card::print();
		std::cout << ", Attack power: " << this->attack_power << ", Defence power: " << this->defence_power << std::endl;
	}
	~HeroCard() override = default;
protected:
	unsigned attack_power;
	unsigned defence_power;
};
class MagicCard : virtual public Card {
public:
	MagicCard() = default;
	MagicCard(const std::string& initial_name, const unsigned& initial_id, const
		unsigned& initial_image_id,
		const std::string& initial_effect) : Card(initial_name, initial_id,
			initial_image_id), effect(initial_effect) {
	}
	void set_effect(const std::string& new_effect)
	{
		this->effect = new_effect;
	}
	std::string get_effect() const
	{
		return this->effect;
	}
	void print() const override
	{
		Card::print();
		std::cout << ", Effect: " << this->effect << std::endl;
	}
	~MagicCard() override = default;
protected:
	std::string effect;
};
class SpecialCard : public HeroCard, public MagicCard {
public:
	SpecialCard() = default;
	SpecialCard(const std::string& initial_name, const unsigned& initial_id,
		const unsigned& initial_image_id,
		const unsigned& initial_attack_power, const unsigned&
		initial_defence_power, const std::string& initial_effect,
		const unsigned& initial_level) : Card(initial_name, initial_id,
			initial_image_id), level(initial_level)
	{
		HeroCard::attack_power = initial_attack_power;
		HeroCard::defence_power = initial_defence_power;
		MagicCard::effect = initial_effect;
	}
	void set_level(const unsigned& new_level)
	{
		this->level = new_level;
	}
	unsigned get_level() const
	{
		return this->level;
	}
	void print() const override
	{
		Card::print();
		std::cout << ", Attack power: " << this->attack_power
			<< ", Defence power: " << this->defence_power
			<< ", Effect: " << this->effect << std::endl;
	}
	~SpecialCard() override = default;
private:
	unsigned level;
};
class Deck {
public:
	static Deck* get_instance()
	{
		return instance;
	}
	void add_card(const HeroCard& new_card)
	{
		this->cards.push_back(new HeroCard(new_card));
	}
	void add_card(const MagicCard& new_card)
	{
		this->cards.push_back(new MagicCard(new_card));
	}
	void add_card(const SpecialCard& new_card)
	{
		this->cards.push_back(new SpecialCard(new_card));
	}
	void print() const
	{
		for (auto* card : cards)
		{
			card->print();
		}
	}
	Deck() = default;
	~Deck()
	{
		for (auto* card : cards)
		{
			delete card;
		}
		delete instance;
	}
private:
	static Deck* instance;
	
	
	std::vector<Card*> cards;
};
Deck* Deck::instance = new Deck();
int main()
{
	HeroCard h1("jsd", 3, 5, 4, 7);
	h1.print();
	MagicCard ma1("mnfcjh", 5, 2, "Kill");
	ma1.print();
	SpecialCard s1("sgfd", 7, 4, 2, 5, "Speak", 5);
	s1.print();
	Deck d;
	d.add_card(h1);
	d.add_card(ma1);
	d.add_card(s1);
	d.print();
	return 0;
}