pragma solidity >=0.5.0;

// This contract describes the Stranger who can add to deposit of PiggyBank but can't withdraw deposit.

// PiggyBank interface
abstract contract PiggyBank {
	function deposit() public payable virtual;
	function withdraw() public virtual;
}

contract Stranger {

	// Receive function to receive plain transfers
	receive() external payable {
	}

	// Modifier that allows public function to accept all external calls.
	modifier alwaysAccept {
		// Runtime function that allows contract to process inbound messages spending
		// its own resources (it's necessary if contract should process all inbound messages,
		// not only those that carry value with them).
		tvm.accept();
		_;
	}

	// State variable storing the number of function addToDeposit was called, initialized with number 1000.
	uint depositCounter = 1000;

	// Function to deposit money to piggy bank.
	function addToDeposit(PiggyBank bankAddress, uint amount) public alwaysAccept {
		bankAddress.deposit.value(amount)();
		depositCounter++;
	}

	// Function to withdraw money from piggy bank.
	function withdrawDeposit(PiggyBank bankAddress) public pure alwaysAccept {
		bankAddress.withdraw();
	}
}
