# Dither 1d values to interpolate high range to low

Originally intended to get a wider dynamic range of RGB LEDs, this
library currently implements a 16 bit class where input values
are converted to a lower range that's cycled each .get() call
to average out to the desired value.

So far I only tested it with an input max of 10000 and output
range of [0-255].

# Future improvements

* Make a C only version.
* Implement as a template to take different bit depths
* Fix bugs if found

# License

GPL v3.0
