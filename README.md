# Dither 1d values to interpolate high range to low

Originally intended to get a wider dynamic range of RGB LEDs, this
library currently implements a 16 bit class where input values
are converted to a lower range that's cycled each .get() call
to average out to the desired value.

So far I only tested it with an input max of 10000 and output
range of [0-255].

# Example output of main.cpp (which tests dither1d.cpp / .h)
```
[ Testing 25% ]
Target(2500) * omax(255) / imax(10000) => val( 63)
Target(2530) * omax(255) / imax(10000) => val( 64)
Target(2521) * omax(255) / imax(10000) => val( 64)
Target(2512) * omax(255) / imax(10000) => val( 64)
Target(2503) * omax(255) / imax(10000) => val( 63)
Target(2533) * omax(255) / imax(10000) => val( 64)
Target(2524) * omax(255) / imax(10000) => val( 64)
Target(2515) * omax(255) / imax(10000) => val( 64)
...
[ Testing literal .25 ]
Target( 30) * omax(255) / imax(10000) => val(  0)
Target( 39) * omax(255) / imax(10000) => val(  0)
Target( 48) * omax(255) / imax(10000) => val(  1)
Target( 18) * omax(255) / imax(10000) => val(  0)
Target( 27) * omax(255) / imax(10000) => val(  0)
Target( 36) * omax(255) / imax(10000) => val(  0)
Target( 45) * omax(255) / imax(10000) => val(  1)
...
[ Testing 50% ]
Target(5039) * omax(255) / imax(10000) => val(128)
Target(5020) * omax(255) / imax(10000) => val(128)
Target(5001) * omax(255) / imax(10000) => val(127)
Target(5021) * omax(255) / imax(10000) => val(128)
...
```

# Future improvements

* Make a C only version.
* Implement as a template to take different bit depths
* Fix bugs if found

# License

GPL v3.0
