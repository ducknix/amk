#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <iostream>
#include <stdexcept>

/**
 * @brief The boost::program_options library provides a simple and flexible
 * interface for parsing command-line options, configuration files, and
 * environment variables into C++ variables. This namespace contains all the
 * components of the library.
 *
 * @details The program_options library provides a simple and flexible interface
 * for parsing command-line options, configuration files, and environment
 * variables into C++ variables. It supports many different styles of options,
 * such as options with and without arguments, options that take multiple
 * arguments, and options that specify a value or a list of values. It also
 * provides a way to group options into logical sections, and to define
 * hierarchical relationships between options.
 *
 * @note The program_options library is part of the Boost library, and must be
 * included in the code using the following line: #include
 * <boost/program_options.hpp>.
 */
namespace po = boost::program_options;

/**
 * @brief This function is the main function of the program. It is responsible
 * for parsing the command line arguments and executing the appropriate
 * functions based on the arguments provided.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The array of arguments passed to the program.
 * @return int Returns an integer value indicating the status of the program.
 */
int main(int argc, char** argv) {
  try {
    // create a options description for the command line arguments
    po::options_description desc("AMK Options");

    desc.add_options()
        ("help,h", "produce help message")
        ("input,i", po::value<std::string>(), "amkfile path input")
        ("verbose,v", "verbose output")("debug,d", "debug output")
        ("version,V", "print version")
    ;

    // create a variables map to store the command line arguments
    po::variables_map vm;

    // parse the command line arguments and store them in the variables map
    po::store(po::parse_command_line(argc, argv, desc), vm);

    // notify any changes to the variables map
    po::notify(vm);

    // check if the help argument was provided, and if so, print the help
    // message and exit
    if (vm.count("help")) {
      std::cout << desc << std::endl;
      return 0;
    }

    // check if the version argument was provided, and if so, print the version
    // and exit
    if (vm.count("version")) {
      std::cout << "version 0.0.1" << std::endl;
      return 0;
    }

    // retrieve the input file path from the variables map
    std::string input_file = vm.at("input").as<std::string>();

    // check if the verbose argument was provided, and if so, print the input
    // file path
    if (vm.count("verbose")) {
      std::cout << "input file: " << input_file << std::endl;
    }

    // check if the debug argument was provided, and if so, print the debug
    // message
    if (vm.count("debug")) {
      std::cout << "debug output" << std::endl;
    }

  } catch (std::out_of_range& e) {
    // if no arguments were provided, print an error message and exit
  }

  return 0;
}