/*
 * IORegistry.h
 *
 * Created: 23/05/2018 12:54:53
 *  Author: Javier Rodriguez Posada
 */ 


#ifndef IOREGISTRY_H_
#define IOREGISTRY_H_


namespace RegistryManager
{
	// Represent the structure of a IO registry for a pin.
	struct IORegistryPinStruct
	{
		// Pointer to each of the registries. It HAS to be volatile.
		volatile unsigned char* pin;
		volatile unsigned char* port;
		volatile unsigned char* ddr;

		// Bit mask to apply to each registry.
		unsigned char bitmask;
	};

	class IORegistry
	{
		public:
			// Sets the pin as output.
			// In order to do so it modifies the registry DDRx.
			inline static void SetOutput(unsigned char pin)
			{
				IORegistryPinStruct registry;
				GetIORegistryPinStruct(&registry,pin);
				SetOutput(&registry);
			}
			
			// Sets the pin as input.
			// In order to do so it modifies the registry DDRx.
			inline static void SetInput(unsigned char pin)
			{
				IORegistryPinStruct registry;
				GetIORegistryPinStruct(&registry,pin);
				SetInput(&registry);
			}

			// Sets the pin to a digital low.
			// In order to do so it modifies the registry PORTx.
			inline static void SetLow(unsigned char pin)
			{
				IORegistryPinStruct registry;
				GetIORegistryPinStruct(&registry,pin);
				SetLow(&registry);
			}

			// Sets the pin value to a digital high.
			// In order to do so it modifies the registry PORTx.
			inline static void SetHigh(unsigned char pin)
			{
				IORegistryPinStruct registry;
				GetIORegistryPinStruct(&registry,pin);
				SetHigh(&registry);
			}

			// Return whether the pin is set to low or high.
			// This is done reading the registry PINx.
			inline static unsigned char IsHigh(unsigned char pin)
			{
				IORegistryPinStruct registry;
				GetIORegistryPinStruct(&registry,pin);
				return IsHigh(&registry);
			}

		private:
			// Gets the registry associated to the given pin.
			inline static void GetIORegistryPinStruct(IORegistryPinStruct* registry, unsigned char pin)
			{
				
			}

			// Sets the pin as output.
			// In order to do so it modifies the registry DDRx.
			inline static void SetOutput(IORegistryPinStruct* registry)
			{
				*(registry->ddr) |= registry->bitmask;
			}
			
			// Sets the pin as input.
			// In order to do so it modifies the registry DDRx.
			inline static void SetInput(IORegistryPinStruct* registry)
			{
				*(registry->ddr) &= ~(registry->bitmask);
			}

			// Sets the pin to a digital low.
			// In order to do so it modifies the registry PORTx.
			inline static void SetLow(IORegistryPinStruct* registry)
			{
				*(registry->port) &= ~(registry->bitmask);
			}

			// Sets the pin value to a digital high.
			// In order to do so it modifies the registry PORTx.
			inline static void SetHigh(IORegistryPinStruct* registry)
			{
				*(registry->port) |= (registry->bitmask);
			}

			// Return whether the pin is set to low or high.
			// This is done reading the registry PINx.
			inline static unsigned char IsHigh(IORegistryPinStruct* registry)
			{
				return *(registry->pin) & registry->bitmask;
			}
	};
}


#endif /* IOREGISTRY_H_ */