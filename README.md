# Obtrack
an c++ object tracker using the curiously recurring template pattern.

The current version only depends on standard headers.

## Usage
It is header only, just include `ObjectTracker.hpp` and inherit like `struct X : public ObjectTracker<X>`.

## Test

* `prepare`, create the test container image
* `run_test`, run the unit tests inside the container

### Requirements
The project uses docker for providing a defined test environment, so `docker` is required, but for testing only.
