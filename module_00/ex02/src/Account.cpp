/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:46:07 by christophed       #+#    #+#             */
/*   Updated: 2025/05/01 18:41:03 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

static int	_nbAccounts = 0;
static int	_totalAmount = 0;
static int	_totalNbDeposits = 0;
static int	_totalNbWithdrawals = 0;

/* ************************************************************************** */
/*								public methods  							  */
/* ************************************************************************** */

/* ******************************* constructor ****************************** */

Account::Account( int initial_deposit) :
	_accountIndex(++_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
}

/* ******************************* destructor ****************************** */

Account::~Account()
{}

/* ******************************** getters ******************************** */

int 	Account::getNbAccounts()
{
	return (_nbAccounts);
}	

int 	Account::getTotalAmount()
{
	return (_totalAmount);
}

int		Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int		checkAmount( void ) const 
{
	return (checkAmount());
}

void	displayStatus( void ) const
{
	;
}

/* ******************************** setters ******************************** */

void		makeDeposit( int deposit )
{
	int	p_amount(_amount);

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;

}

bool	makeWithdrawal( int withdrawal )
{
	int	p_amount(_amount);

	if (p_amount - withdrawal < 0) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused"
			<< std::endl;
	
		return (false);
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	
	return (true);
}

/* ************************* other public methods ************************** */

void	Account::displayAccountsInfos()
{
	std::cout << getNbAccounts() << ';' << getTotalAmount() << ';'
		<< getNbDeposits() << ';' << getNbWithdrawals() << std::endl;
}

/* ************************************************************************** */
/*								private methods  							  */
/* ************************************************************************** */
	
void	_displayTimestamp( void )
{
	char		buffer[20];
	std::time_t	now = std::time(nullptr);
	std::tm*	utc = std::gmtime(&now);

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", utc);
	std::cout << buffer << std::endl;
}




class Account {


	public:
	
		typedef Account		t;
	
		static int	getNbAccounts( void );
		static int	getTotalAmount( void );
		static int	getNbDeposits( void );
		static int	getNbWithdrawals( void );
		static void	displayAccountsInfos( void );
	
		Account( int initial_deposit );
		~Account( void );
	
		void	makeDeposit( int deposit );
		bool	makeWithdrawal( int withdrawal );
		int		checkAmount( void ) const;
		void	displayStatus( void ) const;
	
	
	private:
	
		static int	_nbAccounts;
		static int	_totalAmount;
		static int	_totalNbDeposits;
		static int	_totalNbWithdrawals;
	
		static void	_displayTimestamp( void );
	
		int				_accountIndex;
		int				_amount;
		int				_nbDeposits;
		int				_nbWithdrawals;
	
		Account( void );
	
	};


