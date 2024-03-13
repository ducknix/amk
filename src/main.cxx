#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>

#include <iostream>
#include <stdexcept>

namespace po = boost::program_options;

int main(int argc, char **argv) {

  try {

    po::options_description desc("AMK Options");

    desc.add_options()
        ("help,h", "produce help message")
        ("input,i", po::value<std::string>(), "amkfile path input")
        ("verbose,v", "verbose output")
        ("debug,d", "debug output")
        ("version,V", "print version");

    po::variables_map vm;

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << desc << std::endl;
      return 0;
    }

    if (vm.count("version")) {
      std::cout << "version 0.0.1" << std::endl;
      return 0;
    }

    std::string input_file = vm.at("input").as<std::string>();

    if (vm.count("verbose")) {
      std::cout << "input file: " << input_file << std::endl;
    }

    if (vm.count("debug")) {
      std::cout << "debug output" << std::endl;
    }

  } catch (std::out_of_range &e) {
    // hiçbir parametre yok
  }

  return 0;
}