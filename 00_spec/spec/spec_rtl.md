# Các bộ sắp xếp chạy

+ một bộ sắp xếp gồm các bước chính đó là:
  + SS_check: kiểm tra xem dữ liệu từ si->ei có đoạn nào giống nhau, đã sắp xếp hay chưa.
  + Partition: tính toán mean của chuỗi từ si->ei, và sắp xếp lại chuỗi với mean, và trả về bị trí của pivot nằm trong mảng.
  + Division: chia mảng thành nhiều phần và tiếp tục các phần con trong đó.
  + Sort: module chính tổng thể của thuật toán sắp xếp, nơi mà khai bao vị trí bắt đầu và kết thúc của mảng cần sắp xếp.
+ SS_Check
  + Tạm thời bỏ qua việc check.
  + SS_read_data: Cho phép đọc dữ liệu từ si->ei. Nghĩa là giá trị đầu ra chỉ đơn giản là enable read data và address read data cho bộ nhớ.
  + SS_write_data: Cho phép ghi ngược giá trị từ si->ei vào lại bộ nhớ.
+ Partition
  + PA_cal_mean: Đầu tiên cần tính giá trị mean của mảng bắt đầu từ si->ei.
    + PA_division_alg: Sử dụng để có thể sử dụng thuật toán chia.
    + PA_cal_sum: Cho phép tính giá trị tổng từ bộ nhớ từ si->ei.
    + PA_cal_depth_addr: Cho phép tính ra giá trị tổng số thành phần từ si->ei (tức là ei-si+1).
  + PA_partition: giúp phân chia lại bộ nhớ phân theo mean.
    + PA_swap_and_compare: Sử dụng mean để so sánh các giá trị hiện tại với mean, và quyết định giá trị đó lớn hay nhỏ hơn mean.
    + PA_buf_less: bộ nhớ tạm chứa các giá trị nhỏ hơn mean (có thể là FIFO, Flip-Flop, BRAM,...).
    + PA_buf_greater: tương tự bộ PA_buf_less nhưng là lưu các giá trị lớn hơn mean.
      + Note: về bộ buf lưu giá trị thì các giá trị nhỏ hơn mean được lưu thẳng vào Main Memory, còn các giá trị lớn hơn thì phải lưu trữ lại vào một bộ nhớ đệm. Sau khi xét hết Main Memory thì cũng sẽ cho ta được BI (position of partition return). 
    + PA_write_data: bộ ghi dữ liệu ngược vào bộ nhớ chính với thứ tự là ghi giá trị của bộ less trước sau đó đến greater.
+ Division
  + DI_control: có trách nhiệm phân bổ công việc cho việc quyết định các giá si và ei.

# Triển khai các bộ

## SS_Check

### `SS_read_data`:

```SystemVerilog
    module SS_read_data #(
        parameter SIZE_ADDR = 6 ,
        parameter SIZE_DATA = 8
    )(
        input logic                     i_clk       ,
        input logic                     i_rst_n     ,

        input logic                     i_start_read_data,
        input logic                     i_en_read_data,

        input logic [SIZE_ADDR-1:0]     i_si_ram    ,
        input logic [SIZE_ADDR-1:0]     i_ei_ram    ,

        input logic [SIZE_DATA-1:0]     i_data_ram  ,
        output logic [SIZE_ADDR-1:0]    o_addr_ram  ,

        output logic [SIZE_DATA-1:0]    o_data_ram  ,
        output logic                    o_data_valid,

        output logic                    o_done_read_data
    );
```

+ `i_start_read_data`: Tín hiệu cho biết bắt đầu thời điểm bắt đầu đếm từ si, chỉ quan tâm đến tín hiệu từ 0->1 là tín hiệu bắt đầu, bất chấp bộ đã đếm address đến đâu thì có dấu hiệu của việc start (0->1) thì luôn bắt đầu đếm lại từ đầu.
+ `i_en_read_data`: Tín hiệu cho phép bộ SS_read_data tiếp tục đếm từ lên (đồng nghĩa là +1 vào addr), sau khi đếm đến giá trị addr cuối cùng tức là `o_done_read_data=1'b1` thì dù có tín hiệu `i_en_read_data` bật lên cũng không thể đếm lên được trừ khi có tín hiệu `i_start_read_data` kích lại.
+ `i_si_ram` và `i_si_ram`: là hai giá trí khởi tạo tạo thời điểm tín hiệu `i_start_read_data` có hiệu lực.
+ `i_data_ram`: là đầu vào của dữ liệu đọc được từ Memory.
+ `o_addr_ram`: là địa chỉ cần đọc ở Memory.
+ `o_data_ram`: là dữ liệu đọc được tương ướng với `o_addr_ram` đó, lưu ý là dữ liệu được được tại address đó sẽ trễ sau đó 1 chu kỳ.
+ `o_data_valid`: là tín hiệu cho biết giá trị đó có hiệu lực hay không, tín hiệu có hiệu lực là khi tại thời điểm xuất `o_addr_ram` đó có tín hiệu `i_en_read_data` và đang trong khoảng hợp lệ từ si->ei khi bộ đã được cho phép khởi động (có start).
+ `o_done_read_data`: tín hiệu cho biết bộ đã hoàn thành đọc dữ liệu từ từ si->ei, bộ được cho là hoàn thành khi đã hoàn thành đọc xong giá trị tại `i_ei_ram` là valid, lưu ý là done bật lên sau chu kỳ mà data của addr cuối đã xong.

```wavedrom

```

### `SS_write_data`

```SystemVerilog
    module SS_write_data #(
        parameter SIZE_ADDR = 6 ,
        parameter SIZE_DATA = 8
    )();
```
