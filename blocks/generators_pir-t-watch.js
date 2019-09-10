Blockly.JavaScript['pir_setup'] = function(block) {
    var number_pin = block.getFieldValue('PIN');
    var code = `#SETUPpinMode(${number_pin}, INPUT_PULLUP);#ENDdigitalRead(${number_pin})`;
    return [code, Blockly.JavaScript.ORDER_NONE];
};