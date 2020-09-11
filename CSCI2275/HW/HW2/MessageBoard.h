#include <vector>
// Define struct for items
struct item {
	int for_sale = -1;
	std::string type = "";
	int price = -1;
};

class MessageBoard{
	private:
		std::vector <item> items; //vector of items
		void checkForMatch(item it);

	public:
		void readFile(std::string filename);
		void printItemsSold(item it);
		void printItemsRemaining();
		void postItemToMessageBoard(std::string item, int price, int forSale);

};
