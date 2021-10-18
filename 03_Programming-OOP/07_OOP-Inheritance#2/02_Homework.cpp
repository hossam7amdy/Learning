/// Homework 2: Package Delivery Service
/*
● Design classes (no main) for a package delivery service (E.g. FedEx):
    ○ A standard package has a sender address, receiver address, weight per kg and price per kg
■ Total cost is: weight in kg x price per kg
■ Address is: name, string and city
    ○ A 2-day package is a standard package with an added fixed fee for the total cost
    ○ A heavy package is a standard package for heavy weights attached with extra weight
■ If weight > 100 kg, then extra fees: (weight - 100) * extra fee in kg
    ○ Customer can creates several shipments. Each shipment is set of packages of different types
■ Total shipment price = sum of each package price
■ Each shipment has information of card used for payment
■ Customer has several debit and credit card, each has its information
*/

/// Design

#include<iostream>
#include<vector>
using namespace std;

class Address {
private:
	string name;
	string address;
	string city;
public:
	const string& GetAddress() const {
		return address;
	}

	void SetAddress(const string& address) {
		this->address = address;
	}

	const string& GetCity() const {
		return city;
	}

	void SetCity(const string& city) {
		this->city = city;
	}

	const string& GetName() const {
		return name;
	}

	void SetName(const string& name) {
		this->name = name;
	}
};

class StandardPackage {
private:
	Address sender_address;
	Address reciever_address;
	double weight_kg;
	double price_per_kg;

public:

	StandardPackage(const Address &sender_address, const Address &reciever_address, double weight_kg, double price_per_kg) :
			sender_address(sender_address), reciever_address(reciever_address), weight_kg(weight_kg), price_per_kg(price_per_kg) {
	}

	double TotalCost() const {
		return weight_kg * price_per_kg;
	}

	double GetPricePerKg() const {
		return price_per_kg;
	}

	void SetPricePerKg(double pricePerKg) {
		price_per_kg = pricePerKg;
	}

	const Address &GetRecieverAddress() const {
		return reciever_address;
	}

	void SetRecieverAddress(const Address &recieverAddress) {
		reciever_address = recieverAddress;
	}

	const Address & GetSenderAddress() const {
		return sender_address;
	}

	void SetSenderAddress(const Address &senderAddress) {
		sender_address = senderAddress;
	}

	double GetWeightKg() const {
		return weight_kg;
	}

	void SetWeightKg(double weightKg) {
		weight_kg = weightKg;
	}
};

class TwoDayPackage: public StandardPackage {
private:
	double fixed_fee;

public:
	TwoDayPackage(const Address &sender_address, const Address &reciever_address, double weight_kg, double price_per_kg, double fixed_fee) :
			StandardPackage(sender_address, reciever_address, weight_kg, price_per_kg), fixed_fee(fixed_fee) {
	}

	double TotalCost() const {
		return StandardPackage::TotalCost() + fixed_fee;
	}

	double GetFixedFee() const {
		return fixed_fee;
	}

	void SetFixedFee(double fixedFee) {
		fixed_fee = fixedFee;
	}
};

class HeavyPackage: public StandardPackage {
private:
	const double limit_kg = 100;
	double extra_price_per_kg;
public:
	HeavyPackage(const Address &sender_address, const Address &reciever_address, double weight_kg, double price_per_kg, double extra_price_per_kg) :
			StandardPackage(sender_address, reciever_address, weight_kg, price_per_kg), extra_price_per_kg(extra_price_per_kg) {
	}

	double TotalCost() const {
		double ret = StandardPackage::TotalCost();

		if (GetWeightKg() > limit_kg)
			ret += (GetWeightKg() - limit_kg) * extra_price_per_kg;
		return ret;
	}

	double GetExtraPricePerKg() const {
		return extra_price_per_kg;
	}

	void SetExtraPricePerKg(double extraPricePerKg) {
		extra_price_per_kg = extraPricePerKg;
	}
};

class PaymentCard {
private:
	string card_number;
	double expiry_date;
};

class CreditCard: public PaymentCard {
};

class DebitCard: public PaymentCard {
};

class Shipment {
private:
	// How ugly is such way below?!
	vector<StandardPackage> standard_packages;
	vector<TwoDayPackage> two_day_packages;
	vector<HeavyPackage> heavy_packages;

	CreditCard credit_card;
	DebitCard debit_card;
	bool is_credit_card_used;

public:
	void AddStandardPackage(const StandardPackage & package) {
		standard_packages.push_back(package);
	}
	void AddTwoDayPackage(const TwoDayPackage & package) {
		two_day_packages.push_back(package);
	}
	void AddHeavyPackage(const HeavyPackage & package) {
		heavy_packages.push_back(package);
	}

	void SetCreditCard(const CreditCard &credit_card_) {
		credit_card = credit_card_;
		is_credit_card_used = true;
	}
	void SetDebitCard(const DebitCard &debit_card_) {
		debit_card = debit_card_;
		is_credit_card_used = false;
	}

	double TotalCost() const {
		double total = 0;

		// What is wrong from OO principles here?
		for (auto const & package : standard_packages)
			total += package.TotalCost();

		for (auto const & package : two_day_packages)
			total += package.TotalCost();

		for (auto const & package : heavy_packages)
			total += package.TotalCost();

		return total;
	}
};

class Customer {
private:
	vector<Shipment> shipments;
	vector<CreditCard> credit_cards;
	vector<DebitCard> debit_cards;
public:

	void AddShipment() {

	}
};

int main() {

	return 0;
}
