Blockly.Blocks['pir_setup'] = {
    init: function() {
      this.appendDummyInput()
          .appendField("PIR motion sensor pin")
          .appendField(new Blockly.FieldNumber(21), "PIN");
    this.setOutput(true, "Number");
    this.setColour(120);
    this.setTooltip("");
    this.setHelpUrl("");
    }
  };