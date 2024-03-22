#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;

        for (size_t i = 0; i < desc.size(); i++)
        {
            for (size_t j = 0; j < price.size(); j++)
            {
                if (desc[i].code == price[j].code)
                {
                    Product* newProduct = new Product(desc[i].desc, price[j].price);

                    try
                    {
                        newProduct->validate();
                        priceList += newProduct;
                        delete newProduct;
                    }
                    catch (const std::string str)
                    {
                      delete newProduct;
                      throw str;
                       
                    }
                }
                
            }
        }
        return priceList;

    }
}



