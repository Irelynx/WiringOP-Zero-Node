#include "mcp3422.h"
#include <mcp3422.h>

DECLARE(mcp3422Setup);

// Func : int mcp3422Setup(int pinBase, int i2cAddress, int sampleRate, int gain)

IMPLEMENT(mcp3422Setup) {
  SCOPE_OPEN();
  
  SET_ARGUMENT_NAME(0, pinBase);
  SET_ARGUMENT_NAME(1, i2cAddress);
  SET_ARGUMENT_NAME(2, sampleRate);
  SET_ARGUMENT_NAME(3, gain);
  
  CHECK_ARGUMENTS_LENGTH_EQUAL(4);
  
  CHECK_ARGUMENT_TYPE_INT32(0);
  CHECK_ARGUMENT_TYPE_INT32(1);
  CHECK_ARGUMENT_TYPE_INT32(2);
  CHECK_ARGUMENT_TYPE_INT32(3);
  
  int pinBase = GET_ARGUMENT_AS_INT32(0);
  int i2cAddress = GET_ARGUMENT_AS_INT32(1);
  int sampleRate = GET_ARGUMENT_AS_INT32(2);
  int gain = GET_ARGUMENT_AS_INT32(3);
  
  CHECK_ARGUMENT_IN_INTS(2, sampleRate, (MCP3422_SR_3_75, MCP3422_SR_15, MCP3422_SR_60, MCP3422_SR_240));
  CHECK_ARGUMENT_IN_INTS(3, gain, (MCP3422_GAIN_1, MCP3422_GAIN_2, MCP3422_GAIN_4, MCP3422_GAIN_8));
  
  int res = ::mcp3422Setup(pinBase, i2cAddress, sampleRate, gain);
  
  SCOPE_CLOSE(INT32(res));
}

IMPLEMENT_EXPORT_INIT(mcp3422) {
  EXPORT_FUNCTION(mcp3422Setup);
  
  EXPORT_CONSTANT_INT(MCP3422_SR_3_75);
  EXPORT_CONSTANT_INT(MCP3422_SR_15);
  EXPORT_CONSTANT_INT(MCP3422_SR_60);
  EXPORT_CONSTANT_INT(MCP3422_SR_240);
  
  EXPORT_CONSTANT_INT(MCP3422_GAIN_1);
  EXPORT_CONSTANT_INT(MCP3422_GAIN_2);
  EXPORT_CONSTANT_INT(MCP3422_GAIN_4);
  EXPORT_CONSTANT_INT(MCP3422_GAIN_8);
}