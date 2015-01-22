(function($){
  Drupal.behaviors.ViewsBlockCacheOptimizer = {
    optimized_setting: null,
    attach: function () {
      var _this = this;
      $("#edit-views-block-cache-optimizer").change(function() {
        _this.updateBlockcacheRadios(this.checked);
      });

      $vbco_checkbox = $("#edit-views-block-cache-optimizer");
      if ($vbco_checkbox.length > 0) {
        var checked = $vbco_checkbox.is(':checked');
        if (checked) {
          this.optimized_setting = $('#edit-block-caching input:checked').val();
        }
        this.updateBlockcacheRadios(checked);
      }
    },
    updateBlockcacheRadios: function (is_checked) {
      if (is_checked) {
        // Disable block cache radios if vbco is on.
        $("#edit-block-caching input").attr('disabled', true);
        // If vbco was on initially, restore the optimized setting.
        if (this.optimized_setting) {
          $('#edit-block-caching :radio[value=' + this.optimized_setting + ']').attr('checked', true);
        }
      }
      else {
        $("#edit-block-caching input").removeAttr('disabled');
      }
    }
  };
})(jQuery);
