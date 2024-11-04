#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int przetransportowanyTowar = 0;
    unsigned int liczbaZaglowcow = 0;
    Stocznia stocznia;
    Stocznia::resetTotalCap();

    while (przetransportowanyTowar < towar) {
        Statek* statek = stocznia();
        unsigned int ladunek = statek->transportuj();
        przetransportowanyTowar += ladunek;

        // Sprawdzamy, czy statek jest typu Zaglowiec
        if (dynamic_cast<Zaglowiec*>(statek)) {
            ++liczbaZaglowcow;
        }

        delete statek;

    }
    std::cout << "Całkowita pojemność przetransportowana przez flotę: " << Stocznia::getTotalCap() << std::endl;
    return liczbaZaglowcow;
}