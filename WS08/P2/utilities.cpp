/***********************************************************************
// Workshop 8 Part 2
// Version 1.0
// Author
// Description
//	Name      : Kiarash Kia
//	Student ID: 108688235
//	Email     : kkia2@myseneca.ca
//	
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
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

    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;

        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < price.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    std::unique_ptr<Product> smartptr(new Product(desc[i].desc, price[j].price));
                    smartptr->validate();
                    priceList += std::move(smartptr);
                }
            }
        }

        return priceList;
    }
}
