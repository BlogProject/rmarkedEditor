<template>
  <div class="code-editor">
    <textarea></textarea>
  </div>
</template>

<script>
  window.CodeMirror = require('codemirror')
  require('codemirror/mode/meta')
  export default {
    name: 'codemirror',
    data: function() {
      return {
        content: ''
      }
    },
    props: {
      code: String,
      value: String,
      events: Array,
      unseenLines: Array,
      marker: Function,
      loadtheme: {
        type: Boolean,
        default: function() {
          return true
        }
      },
      debugger: {
        type: Boolean,
        default: function() {
          return true
        }
      },
      options: {
        type: Object,
        required: true
      },
    },
    mounted: function() {
      var _this = this
      this.editor = CodeMirror.fromTextArea(this.$el.firstElementChild, this.options)
      this.editor.setValue(this.code || this.value || this.content)
      this.editor.on('change', function(cm) {
        _this.content = cm.getValue()
        if (!!_this.$emit) {
          _this.$emit('change', _this.content)
          _this.$emit('input', _this.content)
        }
      })
      var events = [
        'scroll',
        'changes',
        'beforeChange',
        'cursorActivity',
        'keyHandled',
        'inputRead',
        'electricInput',
        'beforeSelectionChange',
        'viewportChange',
        'swapDoc',
        'gutterClick',
        'gutterContextMenu',
        'focus',
        'blur',
        'refresh',
        'optionChange',
        'scrollCursorIntoView',
        'update'
      ];
      if (this.events && this.events.length) {
        events = events.concat(this.events)
      }
      for (var i = 0; i < events.length; i++) {
        if (events.indexOf(events[i]) == i) {
          (function(event) {
            _this.editor.on(event, function(a, b, c) {
              _this.$emit(event, a, b, c)
            })
          })(events[i])
        }
      }
      this.$emit('ready', this.editor)
      this.unseenLineMarkers()

      // prevents funky dynamic rendering
      window.setTimeout(function() {
        _this.editor.refresh()
      }, 0)
    },
    beforeDestroy: function() {
      
      // garbage cleanup
      var element = this.editor.doc.cm.getWrapperElement()
      if (element && element.remove) {
        element.remove()
      }
    },
    watch: {
      options: {
        deep: true,
        handler(options, oldOptions) {
          var key
          for (key in options) {
            this.editor.setOption(key, options[key])
          }
        }
      },
      code: function(newVal, oldVal) {
        var editor_value = this.editor.getValue()
        if (newVal !== editor_value) {
          var scrollInfo = this.editor.getScrollInfo()
          this.editor.setValue(newVal)
          this.content = newVal
          this.editor.scrollTo(scrollInfo.left, scrollInfo.top)
        }
        this.unseenLineMarkers()
      },
      value: function(newVal, oldVal) {
        var editor_value = this.editor.getValue()
        if (newVal !== editor_value) {
          var scrollInfo = this.editor.getScrollInfo()
          this.editor.setValue(newVal)
          this.content = newVal
          this.editor.scrollTo(scrollInfo.left, scrollInfo.top)
        }
        this.unseenLineMarkers()
      }
    },
    methods: {
      refresh: function() {
        this.editor.refresh()
      },
      unseenLineMarkers: function () {
        var _this = this
        if (_this.unseenLines !== undefined && _this.marker !== undefined) {
          _this.unseenLines.forEach(line => {
            var info = _this.editor.lineInfo(line)
            _this.editor.setGutterMarker(line, "breakpoints", info.gutterMarkers ? null : _this.marker())
          })
        }
      }
    }
  }
</script>
<style>
.code-editor {
  padding:5px;
  font-size:13px;
}
.code-editor .CodeMirror {
  border:1px solid #c4c4c4;
  padding:0px;
}
</style>

