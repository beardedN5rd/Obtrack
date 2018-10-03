# Obtrack
an C++ object tracker using the curiously recurring template pattern.

The current version only depends on standard headers.

## Usage
It is header only, just include `ObjectTracker.hpp` and inherit like `struct X : public ObjectTracker<X>`.

## Dependencies
It requires C++11 and only uses the C++ standard library.
For testing boost build and boost test are required.

## Test

* `prepare`, create the test container image
* `run_test`, run the unit tests inside the container

### Requirements
The project uses docker for providing a defined test environment, so `docker` is required, but for testing only.
